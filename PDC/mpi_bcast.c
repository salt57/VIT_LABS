#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 100

int main(int argc, char **argv)
{

    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int i, sum = 0;
    int *array = (int *)malloc(sizeof(int) * ARRAY_SIZE);

    if (rank == 0)
    {
        printf("Sourish Gupta - 20BCE0453\n\n");
        // Initialize the array with random values
        for (i = 0; i < ARRAY_SIZE; i++)
        {
            array[i] = rand() % 100;
        }
    }
    double start_time, end_time;
    start_time = MPI_Wtime();

    // Using MPI_Bcast()
    MPI_Bcast(array, ARRAY_SIZE, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate sum of array elements
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        sum += array[i];
    }

    end_time = MPI_Wtime();

    if (rank == 0)
    {
        printf("Using MPI_Bcast(): Sum = %d, Time = %f\n", sum, end_time - start_time);
    }

    sum = 0;
    start_time = MPI_Wtime();

    if (rank == 0)
    {
        // Send the array to all processes using MPI_Send()
        for (i = 1; i < size; i++)
        {
            MPI_Send(array, ARRAY_SIZE, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    }
    else
    {
        // Receive the array from process 0 using MPI_Recv()
        MPI_Recv(array, ARRAY_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Calculate sum of array elements
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        sum += array[i];
    }

    end_time = MPI_Wtime();

    if (rank == 0)
    {
        printf("Using MPI_Send()/MPI_Recv(): Sum = %d, Time = %f\n", sum, end_time - start_time);
    }

    MPI_Finalize();

    return 0;
}
