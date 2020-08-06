/*
*       Parallels and Distributed Systems Exercise 4
*       Essentials lines of code.
*       Author:Michael Karatzas
*       AEM:9137
*/

void pointer_swap(int **a , int **b){
  int * temp=*a;
  *a=*b;
  *b=temp;
}
