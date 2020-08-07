#      Parallels and Distributed Systems Exercise 4
#			 Makefile
#      Author:Michael Karatzas
#      AEM:9137
#			 September 2020

SHELL := /bin/bash
CC = gcc
CFLAGS = -Wall -O3
INCLUDES = -I ./inc

clean:
	find ./ -name "*.a" -o -name "*.o" -o -executable -a -type f | xargs rm -f
	rm tester/*.h


lib: rcm_sequential_a.o  rcm_sequential_b.o
	ar rcs lib/rcm_sequential_a.a lib/rcm_sequential_a.o
	ar rcs lib/rcm_sequential_b.a lib/rcm_sequential_b.o

	rm lib/*.o


rcm_sequential_a.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/rcm_sequential_a.c -o lib/rcm_sequential_a.o -pg

rcm_sequential_b.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/rcm_sequential_b.c -o lib/rcm_sequential_b.o -pg
