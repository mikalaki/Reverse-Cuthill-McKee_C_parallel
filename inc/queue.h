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
typedef struct  {
  int * data;
  int size,capacity,front,rear;
} queue;


//Methods fo queue manipulation.
queue * queueInit(int capacity);
void queueAdd( queue * q, int element);
int queuePoP( queue * q);
bool isEmptyQueue(queue *q);

#endif
