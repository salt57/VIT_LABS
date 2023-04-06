#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

int main(int argc, char **argv)
{
    int rank, size;
    int *data;
    int *sub_data;
    int sub_size;
    int i;
    double start_scatter_gather, end_scatter_gather;
    double start_scatter_reduce, end_scatter_reduce;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Sourish Gupta - 20BCE0453\n\n");
        // Initialize the data array on the master process
        data = malloc(sizeof(int) * ARRAY_SIZE);
        srand(time(NULL));
        for (i = 0; i < ARRAY_SIZE; i++)
        {
            data[i] = rand() % 100;
        }
        printf("Starting scatter-gather method...\n");
        start_scatter_gather = MPI_Wtime();
    }

    // Scatter the data array to all processes
    sub_size = ARRAY_SIZE / size;
    sub_data = malloc(sizeof(int) * sub_size);
    MPI_Scatter(data, sub_size, MPI_INT, sub_data, sub_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Compute the local sum
    int local_sum = 0;
    for (i = 0; i < sub_size; i++)
    {
        local_sum += sub_data[i];
    }

    // Gather the local sums and compute the global sum on the master process
    int global_sum_elems[size];
    MPI_Gather(&local_sum, 1, MPI_INT, &global_sum_elems, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        int global_sum = 0;
        // Compute the average and print the result
        for (int i = 0; i < size; i++)
        {
            global_sum += global_sum_elems[i];
        }

        double avg = (double)global_sum / ARRAY_SIZE;
        end_scatter_gather = MPI_Wtime();
        printf("Average (scatter-gather method): %lf\n", avg);
        printf("Time (scatter-gather method): %lf seconds\n", end_scatter_gather - start_scatter_gather);
    }

    if (rank == 0)
    {
        printf("\nStarting scatter-reduce method...\n");
        start_scatter_reduce = MPI_Wtime();
    }

    // Scatter the data array to all processes
    MPI_Scatter(data, sub_size, MPI_INT, sub_data, sub_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Compute the local sum using MPI_Reduce
    int local_sum_reduce = 0;
    MPI_Reduce(&local_sum, &local_sum_reduce, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        // Compute the average and print the result
        double avg = (double)local_sum_reduce / ARRAY_SIZE;
        end_scatter_reduce = MPI_Wtime();
        printf("Average (scatter-reduce method): %lf\n", avg);
        printf("Time (scatter-reduce method): %lf seconds\n", end_scatter_reduce - start_scatter_reduce);
        free(data);
    }

    free(sub_data);
    MPI_Finalize();
    return 0;
}
