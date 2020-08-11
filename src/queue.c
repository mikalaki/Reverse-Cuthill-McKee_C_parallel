/*
*       Parallels and Distributed Systems Exercise 4
*       Queue's Methods definition.
*       Author:Michael Karatzas
*       AEM:9137
*       September 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define DEBUG 0

/////////QUEUE'S METHODS////////
queue * queueInit(int capacity){
  queue * Q = (queue *)malloc(sizeof(queue));
  Q->data=(int *)malloc(sizeof(int)*capacity);
  Q->capacity=capacity;
  Q->rear=-1;
  Q->front=-1;
  Q->size=0;
  return Q;
}

void queueAdd( queue * q, int element){
  if(  q->rear== (q->capacity-1) ){
    if(DEBUG)printf("\n Queue is full, no elements can be added.");
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
    if(DEBUG)printf("\n Queue is empty, no elements can be retrieved from the queue.");
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
    if(DEBUG)printf("\n Queue is empty, no elements can be retrieved from the queue Q.");
    return true;
  }
  else{
    return false;
  }
}
