# Reverse_Cuthill_McKee_C_parallel
This repo is about the final assigment on the parallels and distributed systems class . In this repo I develop a serial implementation of **Reverse Cuthill Mckee algorithm in C** and its parallel version using **OpenMP**  <br>
## Compiling and Execution of the Program
There are two methods of executing the algorithm.
### Execution Method 1 - via tester program
In order to execute the program via tester program,which is the program in `/tester/test.c`, you have to visit the `/tester` directory and then execute: <br>
`make test_sequential` command in order to test -execute the sequential version of the algorithm or <br>
`make test_openmp` in order to test - execute the parallel (openmp) version of the algorithm. <br> <br>
By executing the tester program , you get 1)the initial matrix pattern , 2)the pattern of the matrix after the permutations and 3)the algorithm execution time, all printed on console.<br>
By default , the one matrix dimension n is set to 20 and the sparsity to 85%.
You can change those parameters in `test.c` file in line 15 and 16 from `MATRIX_DIM` and `SPARSITY` values .<br>

### Execution Method 2- via Benchmarking Program
In order to execute the program via Benchmarking program,which is the program in `/bench/bench.c`, you have to visit the `/bench` directory and then execute: <br>
`make bench_sequential` command in order to test -execute the sequential benchmark of the algorithm or <br>
`make bench_openmp` in order to test - execute the parallel (openmp) benchmark of the algorithm. <br>
By executing the benchmark program , you get the average execution time, of executions, of the algorithm ,for a set of matrix dimensions for agiven sparsity. You can modify those parameters inside the bench.c file.
