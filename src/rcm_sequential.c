/*
*       Parallels and Distributed Systems Exercise 4
*       (Sequential) implementation of Reverse Cuthill Mckee algorithm for sparse matriices in C.
*       Author:Michael Karatzas
*       AEM:9137
*       September 2020
*/
#include <stdio.h>
#include <rcm.h>

#define N 5
#define sparsity 0.05




double * degrees ;
//double * mat ;
double mat[5][5]=
{ 0  ,0.5,0 ,0.2,0 ,
  0.5,0  ,0 ,0  ,0 ,
  0  ,0  ,0 ,0  ,0 ,
  0.2,0  ,0 ,0  ,0 ,
  0  ,0  ,0 ,0  , -0.4016};
