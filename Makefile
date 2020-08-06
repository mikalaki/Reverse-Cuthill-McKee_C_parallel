#      Parallels and Distributed Systems Exercise 4
#			 Makefile
#      Author:Michael Karatzas
#      AEM:9137
#			 September 2020

SHELL := /bin/bash
CC = gcc
CFLAGS = #-Wall -O3
INCLUDES = -I ./inc

clean:
	find ./ -name "*.a" -o -name "*.o" -o -executable -a -type f | xargs rm -f


lib: rcm_sequential.o
	ar rcs lib/rcm_sequential.a lib/rcm_sequential.o


	rm lib/*.o


rcm_sequential.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/rcm_sequential.c -o lib/rcm_sequential.o -pg
