/*
*       Parallels and Distributed Systems Exercise 4
*       (Sequential) implementation of Reverse Cuthill Mckee algorithm for sparse matriices in C.
*       Author:Michael Karatzas
*       AEM:9137
*       September 2020
*/
#include <stdio.h>
#include <stdlib.h>

#include "rcm.h"

#define DEBUG 1

//The function that returns the permutation order array, in respect to the
//reverse Cuthill Mckee algorithm
int * rcm(int ** matrix, int n ){

  int * degrees= (int *) malloc(sizeof(int) * n);
  //in this variable, we will get the order of elements by asceding degree.
  int * AscendingDegrIndexes= (int *) malloc(sizeof(int) * n);

  //creating the Q queue
  queue *  Q = queueInit(n);
  int * R=(int *) malloc(sizeof(int)*n);
  int Rcounter=0;

  //1. Find the degree of each element.
  findDegrees(degrees,matrix,n);
  if(DEBUG)for (size_t i = 0; i < n; i++) {
      printf("\n for line with index=%ld, the degree is %d", i , degrees[i]);

  }

  //2. Sort asceding the degrees and get their indexes.
  //initialize indexes
  for (size_t i = 0; i < n; i++) {
      AscendingDegrIndexes[i]= i;
  }

  //Sorting the degrees and indeces
  mergeSort_degrees_indexes(degrees,AscendingDegrIndexes, 0, n-1);
  if(DEBUG)for (size_t i = 0; i < n; i++) {
      printf("\n  After SORT: for line with index=%ld, the degree is %d", i , degrees[i]);
      printf("\n  After SORT: asx index=%ld,  is %d", i , AscendingDegrIndexes[i]);
  }
  free(degrees);

  for(int i=0 ; i<n ; i++){                                                     //N
    if(AscendingDegrIndexes[i] != -1 ){
      if(DEBUG) printf("\n \n \n ALLL GOOD HERE 1 ");
      queueAdd(Q,AscendingDegrIndexes[i]);
      AscendingDegrIndexes[i]= -1;
      if(DEBUG) printf("\n \n \n ALLL GOOD HERE 2 ");
    }
    if(DEBUG) printf("\n \n \n Q->data[Q->front]= %d", Q->data[Q->front]);

    while (!isEmptyQueue(Q)) { 																							    //Ν

      for (int j = i; j <n; j++) { /// διανύω τον πίνακα , 													Ν
        if ( j != (Q->data[Q->front]) && (matrix[Q->data[Q->front]][AscendingDegrIndexes[j]] != 0) ) {
          queueAdd(Q,AscendingDegrIndexes[j]);
          AscendingDegrIndexes[j]=-1;
        }
      }


      R[Rcounter]= queuePoP(Q);
      Rcounter++;

    }

  }


  //reverse the R vactor
  reverseArray(R,0,n-1);
  return R;


}

void findDegrees(int * degrees,int ** arr, int n ){ // problhma eiani oti den pernaei o 2d pinakas

  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      count += arr[i][j];
    }

    degrees[i]=count;
  }
}



//// Merge sort

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int * arr,int * idx, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];
    int Lidx[n1], Ridx[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        Lidx[i] = idx[l + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        Ridx[j] = idx[m + 1 + j];
    }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            idx[k] = Lidx[i];
            i++;
        }
        else {
            arr[k] = R[j];
            idx[k] = Ridx[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        idx[k] = Lidx[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        idx[k] = Ridx[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort_degrees_indexes(int * arr,int * idx, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort_degrees_indexes(arr,idx, l, m);
        mergeSort_degrees_indexes(arr,idx, m + 1, r);

        merge(arr,idx, l, m, r);
    }
}


// Queue methods
queue * queueInit(int size){
  queue * Q = (queue *)malloc(sizeof(queue));
  Q->data=(int *)malloc(sizeof(int)*size);
  Q->capacity=size;
  Q->rear=-1;
  Q->front=-1;
  Q->size=0;
  return Q;
}

void queueAdd( queue * q, int element){
  if(  q->rear== (q->capacity-1) ){
    printf("\n Queue is full, no elements can be added.");
  }
  else{
    if(q->front == -1){
      q->front=0;
    }
    q->rear++;
    q->size++;
    q->data[q->rear]=element;

  }
}

int queuePoP( queue * q){
  if(   (q-> front)>(q->rear)   ||  ( q->front) == -1 ){
    printf("\n Queue is empty, no elements can be retrieved from the queue. Qfront = ",(q-> front) );
  }
  else{
    int element;
    element = q->data[q->front];
    q->front++;
    q->size--;
    return element;
  }
}


bool isEmptyQueue(queue *q){
  if(   (q-> front)>(q->rear)   ||  ( q->front) == -1 ){
    printf("\n Queue is empty, no elements can be retrieved from the queue Qfront = %d",(q-> front) );
    return true;
  }
  else{
    return false;
  }
}


void reverseArray(int * arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
