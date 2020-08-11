#      Parallels and Distributed Systems Exercise 4
#			 Makefile for tester
#      Author:Michael Karatzas
#      AEM:9137
#			 September 2020

SHELL := /bin/bash
CC = gcc




test_sequential:
	cd ../; make clean; make lib;
	cp ../lib/*.a ../inc/rcm.h  ./;
	$(CC) test.c rcm_sequential.a -o $@
	./test_sequential
	rm test_sequential
