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
#include "queue.h"

//define if the code running in debug status.
#define DEBUG 0

int * rcm(int ** matrix, int n ){

  //Array when the degrees of each node will be stored.
  int * degrees= (int *) malloc(sizeof(int) * n);

  //number of unvisited nodes.
  int nOfUnvisitedNodes=n;

  //Array for indication of not visited nodes, if notVisitedNodes[i]= -1 , node is visited.
  int * notVisitedNodes= (int *) malloc(sizeof(int) * n);

  //creating the Q queue
  queue * Q = queueInit(n);

  //queue for sort a node elements
  queue * nodeNeighbours = queueInit(n);


  int * degreesToShort=(int *)malloc(sizeof(int));

  //R is the permutation order matrix.
  int * R=(int *) malloc(sizeof(int)*n);
  int Rcounter=0;
  int minDegreeElement=0;

  //1. Find the degree of each element.
  calculateDegrees(degrees,matrix,n);
  if(DEBUG)for (size_t i = 0; i < n; i++) {
      printf("\n for line with index=%ld, the degree is %d", i , degrees[i]);

  }


  //initialize indexes of nodes
  for (int i = 0; i < n; i++) {
      notVisitedNodes[i]= i;
  }


  //running a loop for accessing also the elements of disjoint graphs.
  while(nOfUnvisitedNodes > 0){                              //N
    // if(notVisitedNodes[nodeIndex] ==-1) // If the if sentence is true then node with index: nodeIndex is visited.
    //   continue;


    minDegreeElement=0;

    for (int i = 0; i < n; i++)
      if (degrees[i]< degrees[minDegreeElement] && notVisitedNodes[i] !=-1 || notVisitedNodes[minDegreeElement]==-1 )  //// βρίσκουμε ελαχιστου degree σημειο στο notVisited
        minDegreeElement = i;

    if(notVisitedNodes[minDegreeElement]!=-1){
      queueAdd(Q,minDegreeElement);
      notVisitedNodes[minDegreeElement]=-1;
      nOfUnvisitedNodes--;
    }

      while (!isEmptyQueue(Q)) {

        nodeNeighbours->front=-1;
        nodeNeighbours->rear=-1;
        nodeNeighbours->size=0;

        for (int j = 0; j <n; j++) { /// βρισκω γειτονες
          if ( j != (Q->data[Q->front]) && notVisitedNodes[j] !=-1  && (matrix[Q->data[Q->front]][notVisitedNodes[j]] != 0) ) {
            queueAdd(nodeNeighbours,notVisitedNodes[j]);
            if(DEBUG)printf("\n \n I AM HERE!!\n");
          }
        }

        if(nodeNeighbours->size != 0){
          //reallocating the degrees for sortin array.
          int * p =(int *)realloc(degreesToShort,(size_t)sizeof(int)*(nodeNeighbours->size) );
          if (!p) {
            printf("Couldn't Reallocate Memory!\n" );
            exit(1);
          } else {
              degreesToShort = p;
          }

          for (int k = 0; k < nodeNeighbours->size; k++) {
            degreesToShort[k]= degrees[nodeNeighbours->data[k]];
          }

          mergeSort_degrees_indexes(degreesToShort,nodeNeighbours->data, 0, nodeNeighbours->size -1 );

          for (int k = 0; k < nodeNeighbours->size; k++) {
            queueAdd(Q,nodeNeighbours->data[k]);
            notVisitedNodes[nodeNeighbours->data[k]]=-1;
            nOfUnvisitedNodes--;
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

void calculateDegrees(int * degrees,int ** arr, int n ){ // problhma eiani oti den pernaei o 2d pinakas

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
