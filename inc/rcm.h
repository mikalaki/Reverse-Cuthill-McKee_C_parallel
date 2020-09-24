
#ifndef RCM_H
#define RCM_H
/*
*       Parallels and Distributed Systems Exercise 4
*       RCM Functions' Declaration.
*       Author:Michael Karatzas
*       AEM:9137
*       September 2020
*/
#include <stdbool.h>

//! Reverse Cuthill Mckee algorithm, returns the permutation order array R, in respect to the algorithm.
/*!
 \param matrix      The initial symmetric sparse matrix     [n-by-n]
 \param n           Τhe 1-dimension of the matrix             [scalar]
*/
int * rcm(int * matrix,int n);

//Function for calculating the degree of each node.
void calculateDegrees(int * degrees,int * arr, int n );

//Functions for Sorting the neighbours' degrees of a node and their indexes with the same order.
void merge(int * arr,int * idx, int l, int m, int r);
void mergeSort_degrees_indexes(int * arr,int * idx, int l, int r);


//Function for reversing the R vector.
void reverseArray(int * arr, int start, int end) ;

#endif
