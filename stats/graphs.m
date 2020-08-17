%%Graphs for exercise 4 Parallels and Distributed Systems
%-Reverse Cuthill Mckee executions time sequential C and OpenMP.

%Import data in the programm.
dataSequential = importdata('sequential.csv');
dataOpenMP = importdata('openmp.csv');

%Sort data with increasing order of dimension n.
dataSequentialSorted = sort(dataSequential,1);
dataOpenMPSorted = sort(dataOpenMP,1);

    figure();
    plot(dataSequentialSorted(:,1),dataSequentialSorted(:,2),'-*');
    hold on;
    plot(dataOpenMPSorted(:,1),dataOpenMPSorted(:,2),'-*');
    hold on;
    title("Execution time for various n (Sparse matrix has nxn dimension).");
    xlabel("n: matrix dimension");
    ylabel("Execution time (seconds)");

    legend("Sequential verson", "OpenMP version");
