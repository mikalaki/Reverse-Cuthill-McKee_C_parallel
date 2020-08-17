#      Parallels and Distributed Systems Exercise 4
#			 Makefile for bencher
#      Author:Michael Karatzas
#      AEM:9137
#			 September 2020

SHELL := /bin/bash
CC = gcc




bench_sequential:
	cd ../; make clean; make lib;
	cp ../lib/*.a ../inc/rcm.h  ./;
	$(CC) bench.c rcm_sequential.a -o $@
	./bench_sequential
	rm bench_sequential

bench_openmp:
	cd ../; make clean; make lib;
	cp ../lib/*.a ../inc/rcm.h  ./;
	$(CC) bench.c rcm_openmp.a -o $@ -fopenmp
	./bench_openmp
	rm bench_openmp
