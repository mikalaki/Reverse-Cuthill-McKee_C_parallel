#      Parallels and Distributed Systems Exercise 4
#			 Makefile
#      Author:Michael Karatzas
#      AEM:9137
#			 September 2020

SHELL := /bin/bash
CC = gcc
#CFLAGS = -Wall -O3
INCLUDES = -I ./inc

clean:
	find ./ -name "*.a" -o -name "*.o" -o -executable -a -type f | xargs rm -f
	rm tester/*.h


lib: rcm_sequential.o rcm_openmp.o queue.o
	ar rcs lib/rcm_sequential.a lib/rcm_sequential.o lib/queue.o
	ar rcs lib/rcm_openmp.a lib/rcm_openmp.o lib/queue.o

	rm lib/*.o


rcm_sequential.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/rcm_sequential.c -o lib/rcm_sequential.o

rcm_openmp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/rcm_openmp.c -o lib/rcm_openmp.o -fopenmp

queue.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/queue.c -o lib/queue.o
