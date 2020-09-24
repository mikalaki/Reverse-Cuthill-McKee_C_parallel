# Reverse_Cuthill_McKee_C_parallel
This repo is about the final assigment on the parallels and distributed systems class . In this repo I develop a serial implementation of **Reverse Cuthill Mckee algorithm in C** and its parallel version using **OpenMP**  <br>
## Compiling and Execution of the Program
There are two methods of executing the algorithm.
### Execution Method 1 - via tester programm
In order to execute the programm via tester programm,which is the programm located in `/tester/test.c` you have to visit the `/tester` directory and then execute: <br>
`make test_sequential` command in order to test -execute the sequential version of the algorithm or <br>
`make test_openmp` in order to test - execute the parallel (openmp) version of the algorithm. <br>
By executing the tester programm , you get 1)the initial matrix pattern , 2)the pattern of the matrix after the permutations and 3)the algorithm execution time .<br>
By default , the one matrix dimension n is set to 20 and the sparsity to 85%.<br>
You can change those parameters in `test.c` file in line 15 and 16 from `MATRIX_DIM` and `SPARSITY` values .<br>


For executing the program you have first to compile it ,by executing the command bellow inside the project folder :<br>
`gcc prod-cons_multithreading.c myFunctions.c -pthread -o program.out -lm -O3`<br>
after compilation finish you are able to execute the programm with the following command<br>
`./program.out p q` , where **p is the number of producer threads** you want to have and **q the number of consumers**,for instance if you want to have 4 producer threads and 4 consumers threads you have to run the command:<br>
`./program.out 4 4`

### Execution Method 2-Benchmarking
If you want to run the programm for a compination of **p** and **q** values, you can edit the *bench.sh* file and set the p and q values , for which you want to run the programm, in the two for loops . After editing the file , by running :<br>
`./bench.sh` <br>
in the terminal , the programm gets compiled and execute for the parameters you set.
