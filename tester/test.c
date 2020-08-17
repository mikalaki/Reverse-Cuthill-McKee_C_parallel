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
#define MATRIX_DIM 20
#define SPARSITY 0.85

struct timeval start, finish;
double elapsed;

////Function for rows and columns permutations of arr martrix given a permutation order array R.
void permute(int * arr,int * R ,int n);

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



  //Initialize the symmetric sparse matrix
  initSparseMatrix(mat,(double)SPARSITY ,n);




/*
  // int mat[MATRIX_DIM*MATRIX_DIM]=
  // { 0  ,1  ,0 ,1  ,0 , 0 , 0 ,0,
  //   1  ,0  ,0 ,0  ,0 , 1 , 0 ,0,
  //   0  ,0  ,0 ,0  ,0 , 0 , 1 ,0,
  //   1  ,0  ,0 ,0  ,0 , 0 , 0 ,1,
  //   0  ,0  ,0 ,0  ,1 , 1 , 0 ,0,
  //   0  ,1  ,0 ,0  ,1 , 0 , 1 ,0,
  //   0  ,0  ,1 ,0  ,0 , 1 , 0 ,0,
  //   0  ,0  ,0 ,1  ,0 , 0 , 0 ,1
  // };

   // // //INITIALIZE TEST array
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

   //Print the initial symmetric sparse matrix pattern.
   for (int i=0; i<n ; i++){
     printf("\n|");
     for (int j = 0; j < n; j++) {
       if(mat[i*n+j])
         printf(" # ", mat[i*n+j]);
       else
         printf("   ");
     }
     printf("|");
   }
   printf("\n \n");


    //GET the running time of the treebuild
      // gettimeofday(&start,NULL);
     int * R= rcm(mat, n);
     // gettimeofday(&finish,NULL);
     // elapsed = (finish.tv_sec - start.tv_sec);
     // elapsed += (finish.tv_usec - start.tv_usec) / 1000000.0;

     
    printf("\n!!!!!!!!!!!!!!THE R MATRIX: !!!!!!\n [ ");
    for (size_t i = 0; i < n; i++) {
      printf("%d ",R[i]);
    }
    printf("]");

  //Permute the initial matrix with the order of R.
  permute(mat,R ,n);


  printf("\nThe matrix we get after RCM permutations:\n");
  //Print the permuted matrix pattern.
  for (int i=0; i<n ; i++){
    printf("\n|");
    for (int j = 0; j < n; j++) {
      if(mat[i*n+j])
        printf(" # ", mat[i*n+j]);
      else
        printf("   ");
    }
    printf("|");
  }
  printf("\n \n");


  // printf("\nThe algorithm took %lf seconds! \n", elapsed );


  printf("\n!!!!!!!!!!!!!!!!!!!!!!!! \n!Tester Run Succesfully!\n!!!!!!!!!!!!!!!!!!!!!!!! \n \n ");
}




//Function for initializing a sparse symmetric matrix with given sparsity
void initSparseMatrix(int * arr, double sparsity , int n){

  //initialize srand().
  // srand(time(0));
  //comment this out to have the same matrix in both sequential and openmp executions.

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


//Function for initializing a sparse symmetric matrix with given sparsity
void permute(int * arr,int * R ,int n){

  int * arr2 =  (int *)malloc(sizeof(int )*n * n ) ;


  //permute rows
  for (int i=0; i<n ; i++){
    for(int j=0; j<n ; j++){
      arr2[i*n+j]=arr[R[i]*n+j];
    }
  }

  //permute columns
  for (int i=0; i<n ; i++){
    for(int j=0; j<n ; j++){
      arr[i*n+j]=arr2[i*n+R[j]];
    }
  }



}
