#      Parallels and Distributed Systems Exercise 4
#			 Makefile for tester
#      Author:Michael Karatzas
#      AEM:9137
#			 September 2020

SHELL := /bin/bash
CC = gcc



test_sequential_a:
	cd ../; make clean; make lib;
	cp ../lib/*.a ../inc/rcm.h ./;
	$(CC) test.c rcm_sequential_a.a -o $@
	./test_sequential_a
	rm test_sequential_a

test_sequential_b:
	cd ../; make clean; make lib;
	cp ../lib/*.a ../inc/rcm.h ./;
	$(CC) test.c rcm_sequential_b.a -o $@
	./test_sequential_b
	rm test_sequential_b
