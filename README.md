# Reverse_Cuthill_McKee_C_parallel
This repo is about the final assigment on the parallels and distributed systems class . In this repo I develop a serial implementation of **Reverse Cuthill Mckee algorithm in C** and its parallel version using **OpenMP**  <br>
## Compiling and Execution of the Program
There are two methods of executing the algorithm.
### Execution Method 1 - via tester programm
In order to execute the programm via tester programm,which is the programm located in `/tester/test.c` you have to visit the `/tester` directory and then execute: <br>
`make test_sequential` command in order to test -execute the sequential version of the algorithm or <br>
`make test_openmp` in order to test - execute the parallel (openmp) version of the algorithm. <br>
By executing the tester programm , you get 1)the initial matrix pattern , 2)the pattern of the matrix after the permutations and 3)the algorithm execution time, all printed on console.<br>
By default , the one matrix dimension n is set to 20 and the sparsity to 85%.<br>
You can change those parameters in `test.c` file in line 15 and 16 from `MATRIX_DIM` and `SPARSITY` values .<br>




### Execution Method 2- via Benchmarking Programm

