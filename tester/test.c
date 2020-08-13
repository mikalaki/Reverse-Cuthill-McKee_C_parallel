/*
*       Parallels and Distributed Systems Exercise 4
*       Tester programm for Reverse Cuthill Mckee.
*       Author:Michael Karatzas
*       AEM:9137
*       September 2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "rcm.h"
#include  <time.h>


//The initial sparse matrix dimension and sparsity
#define MATRIX_DIM 210
#define SPARSITY 0.79

struct timespec start, finish;
double elapsed;

//Function for initializing a sparse symmetric matrix with given sparsity
void initSparseMatrix(int * arr, double sparsity , int n);

//Function for initializing a sparse symmetric matrix with given sparsity
int randOneOrZero(double zeroProbability);

int main(int argc, char const *argv[]) {
  int n = MATRIX_DIM;
  clock_t t;
  double time_taken;


  //Allocating memory in the heap for the sparse Matrix.
  int * mat = (int *)malloc(sizeof(int )*n * n ) ;
  // for (int i=0; i<n ; i++){
  //   mat[i] = (int *)malloc(sizeof(int) * n ) ;
  // }



  //Initialize
  initSparseMatrix(mat,(double)SPARSITY ,n);

  //Print the initial symmetric sparse array.
  printf("\n [");
  for (int i=0; i<n ; i++){
    for (int j = 0; j < n; j++) {
      printf(" %d ", mat[i*n+j]);
    }
    printf("\n  ");
  }

  printf("]");



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



  //GET the running time of the treebuild
  clock_gettime(CLOCK_MONOTONIC, &start);
   int * R= rcm(mat, n);
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;


  printf("\n!!!!!!!!!!!!!!THE R MATRIX: !!!!!!\n [ ");
  for (size_t i = 0; i < n; i++) {
    printf("%d ",R[i] +1 );
  }
  printf("]");

  printf("\nThe algorithm took %lf seconds! \n", elapsed );


  printf("\n!!!!!!!!!!!!!!!!!!!!!!!! \n!Tester Run Succesfully!\n!!!!!!!!!!!!!!!!!!!!!!!! \n \n ");
}




//Function for initializing a sparse symmetric matrix with given sparsity
void initSparseMatrix(int * arr, double sparsity , int n){

  // //initialize srand().
  // srand(time(0));


  for (int i=0; i<n ; i++){
    for (int j = 0; j < n; j++) {
      //Main diagonal Matrix elements.
      if (i == j)//
         //arr[i][j] = 0; //from a node I cannot access the same node.
         arr[i*n+j] =randOneOrZero((double)sparsity);
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
