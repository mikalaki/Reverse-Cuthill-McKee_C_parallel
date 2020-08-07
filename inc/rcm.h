
#ifndef RCM_H
#define RCM_H

#include <stdbool.h>

typedef struct  {
  int * data;
  int size,capacity,front,rear;
} queue;

//! Reverse Cuthill Mckee algorithm
/*!
 \param matrix      The initial symmetric sparse matrix     [n-by-n]
 \param n           Τhe dimension of the matrix             [scalar]
 NOTE: Both matrices G and w are stored in row-major format.
*/
int * rcm(int ** matrix,int n);

//Function for calculating the degree of each row.
void findDegrees(int * degrees,int ** arr, int n );

void merge(int * arr,int * idx, int l, int m, int r);
void mergeSort_degrees_indexes(int * arr,int * idx, int l, int r);

queue * queueInit(int size);
void queueAdd( queue * q, int element);
int queuePoP( queue * q);
bool isEmptyQueue(queue *q);


void reverseArray(int * arr, int start, int end) ;

#endif
