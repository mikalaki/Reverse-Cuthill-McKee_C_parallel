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

#define MATRIX_DIM 5
#define SPARSITY 0.05


int main(int argc, char const *argv[]) {

  int n = MATRIX_DIM;

  int ** mat = (int **)malloc(sizeof(int *) * n ) ;
  for (int i=0; i<n ; i++){
    mat[i] = (int *)malloc(sizeof(int) * n ) ;
  }

  // int mat[5][5]=
  // {{ 0  ,1  ,0 ,1  ,0 },
  //  { 1  ,0  ,0 ,0  ,0 },
  //  { 0  ,0  ,0 ,0  ,0 },
  //  { 1  ,0  ,0 ,0  ,0 },
  //  { 0  ,0  ,0 ,0  ,1 }};

   //INITIALIZE TEST array
   mat[0][0] = 0;
   mat[0][1] = 1;
   mat[0][2] = 0;
   mat[0][3] = 1;
   mat[0][4] = 0;
   mat[1][0] = 1;
   mat[1][1] = 0;
   mat[1][2] = 0;
   mat[1][3] = 0;
   mat[1][4] = 0;
   mat[2][0] = 0;
   mat[2][1] = 0;
   mat[2][2] = 0;
   mat[2][3] = 0;
   mat[2][4] = 0;
   mat[3][0] = 1;
   mat[3][1] = 0;
   mat[3][2] = 0;
   mat[3][3] = 0;
   mat[3][4] = 0;
   mat[4][0] = 0;
   mat[4][1] = 0;
   mat[4][2] = 0;
   mat[4][3] = 0;
   mat[4][4] = 1;

   
  int * R= rcm(mat, n);


  printf("\n!!!!!!!!!!!!!!THE R MATRIX: !!!!!!\n [ ");
  for (size_t i = 0; i < n; i++) {
    printf("%d ",R[i] +1 );
  }
  printf("]");


  printf("\n!!!!!!!!!!!!!!!!!!!!!!!! \n!Tester Run Succesfully!\n!!!!!!!!!!!!!!!!!!!!!!!! \n \n ");
}
