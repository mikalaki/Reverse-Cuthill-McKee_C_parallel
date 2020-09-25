/*
*
*       Parallels and Distributed Systems Exercise 4
*       Benchmark programm for Reverse Cuthill Mckee.
*       Author:Michael Karatzas
*       AEM:9137
*       September 2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "rcm.h"
#include  <time.h>


//The initial sparse matrix sparsity
#define SPARSITY 0.80
#define N_EXECUTIONS 5 // number of executions for each test

// An array that stores the matrix dimensions , for the benchmark .
int dimensions[]={ 100 ,500, 1000, 2000, 5000, 10000, 15000, 20000, 25000, 30000};

struct timeval start, finish;
double elapsed;

//Function for initializing a sparse symmetric matrix with given sparsity and dimension
void initSparseMatrix(int * arr, double sparsity , int n);

//Function for generation of 0 and 1 , with given probability for zeros.
int randOneOrZero(double zeroProbability);

//main function of benchmark programm
int main(int argc, char const *argv[]) {

  clock_t t;
  double time_taken;
  int * mat = (int *)malloc(sizeof(int )*2) ;
  if( !mat  ){
    printf("Problem Allocating Memory!\n" );
    exit(1);
  }

  for(int ii=0;ii<10;ii++){ // this loop is for scanning the simensions array in ln 20
    //Allocating and reallocationg memory in the heap for the sparse Matrix.
    if(!ii)
      mat = (int *)malloc(sizeof(int )*dimensions[ii]* dimensions[ii] ) ;
    else
      mat=(int *) realloc(mat, (size_t)dimensions[ii]* dimensions[ii]*sizeof(int));

    if( !mat  ){
      printf("Problem Allocating Memory!\n" );
      exit(1);
    }

    //pointer for the csv file.
    FILE *pointerToFile;



    //Initialize the symmetric sparse matrix.
    initSparseMatrix(mat,(double)SPARSITY ,dimensions[ii]);
/*

    // //Print the initial symmetric sparse array.
    // printf("\n [");
    // for (int i=0; i<n ; i++){
    //   for (int j = 0; j < n; j++) {
    //     printf(" %d ", mat[i*n+j]);
    //   }
    //   printf("\n  ");
    // }
    // printf("]");



    // int mat[5][5]=
    // {{ 0  ,1  ,0 ,1  ,0 },
    //  { 1  ,0  ,0 ,0  ,0 },
    //  { 0  ,0  ,0 ,0  ,0 },
    //  { 1  ,0  ,0 ,0  ,0 },
    //  { 0  ,0  ,0 ,0  ,1 }};

     // //INITIALIZE TEST array
     // mat[0*n+0] = 0;
     // mat[0*n+1] = 1;
     // mat[0*n+2] = 0;
     // mat[0*n+3] = 1;
     // mat[0*n+4] = 0;
     // mat[1*n+0] = 1;
     // mat[1*n+1] = 0;
     // mat[1*n+2] = 0;
     // mat[1*n+3] = 0;
     // mat[1*n+4] = 0;
     // mat[2*n+0] = 0;
     // mat[2*n+1] = 0;
     // mat[2*n+2] = 0;
     // mat[2*n+3] = 0;
     // mat[2*n+4] = 0;
     // mat[3*n+0] = 1;
     // mat[3*n+1] = 0;
     // mat[3*n+2] = 0;
     // mat[3*n+3] = 0;
     // mat[3*n+4] = 0;
     // mat[4*n+0] = 0;
     // mat[4*n+1] = 0;
     // mat[4*n+2] = 0;
     // mat[4*n+3] = 0;
     // mat[4*n+4] = 1;
*/

    double meanElapsed=0;
    //execute the algorithm N_EXECUTIONS time in order to get the average
    for( int jj =0; jj <N_EXECUTIONS; jj++){
      elapsed=0;
      //GET the running time of the algorithm executions.
      gettimeofday(&start,NULL);
       int * R= rcm(mat, dimensions[ii]);
      gettimeofday(&finish,NULL);
      elapsed = (finish.tv_sec - start.tv_sec);
      elapsed += (finish.tv_usec - start.tv_usec) / 1000000.0;
      meanElapsed+=elapsed;
    }
    //Getting the average executionTime by divede the sum of executions with N_EXECUTIONS (number of executions)
    meanElapsed/=N_EXECUTIONS;


    //printing the execution time results in console and in file.
    printf("The algorithm for dimension=%d took %lf seconds in average! \n", dimensions[ii], meanElapsed );
    pointerToFile=fopen("sequential.csv","a");
    fprintf(pointerToFile,"%d,%lf\n",dimensions[ii],meanElapsed);

  }

  printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n!Bench Programm Run Succesfully!!\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n \n ");
}




//Function for initializing a sparse symmetric matrix with given sparsity
void initSparseMatrix(int * arr, double sparsity , int n){

  //initialize srand().
  srand(time(0));


  for (int i=0; i<n ; i++){
    for (int j = 0; j < n; j++) {
      //Main diagonal Matrix elements.
      if (i == j)//
         //arr[i][j] = 0; //from a node I cannot access the same node.
         arr[i*n+j] =randOneOrZero((double)sparsity); // a node can access itself.
      //Other elements of the matrix. (symmetric elements)
      else if (i>j){
        arr[i*n+j]=randOneOrZero((double)sparsity);
        arr[j*n+i]=arr[i*n+j];
      }
      }
  }

}




//Function for generation of 0 and 1 , with given probability for zeros.
int randOneOrZero(double zeroProbability) {
    //get random number in [0..1]
    double rndDouble = (double)rand() / RAND_MAX;
    if(rndDouble<zeroProbability)
      return 0;
    else
      return 1;
}
