#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
/*
*       Parallels and Distributed Systems Exercise 4
*       Queue implementation .
*       Author:Michael Karatzas
*       AEM:9137
*/
//Struct for queue implementation
// data: array for storing queue's elements
// size: the number of current valid elements of the queue
// capacity: the capacity of the queue.
// front, rear: the index of the data array element , the front and rear points to.
typedef struct  {
  int * data;
  int size,capacity,front,rear;
} queue;


//Methods fo queue manipulation.
//Queue initialization
queue * queueInit(int capacity);

// Add new element
void queueAdd( queue * q, int element);

// Pop element from the queue
int queuePoP( queue * q);

//returns if queue is empty
bool isEmptyQueue(queue *q);

#endif
