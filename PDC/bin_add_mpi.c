#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank, size, value;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 3)
    {
        printf("This program must be run with 3 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // process 0 sends binary value 001 to process 1
    if (rank == 0)
    {
        printf("Sourish Gupta - 20BCE0453\n\n");
        value = 1;
        MPI_Ssend(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        while (1)
        {
            MPI_Recv(&value, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
            if (value < 7)
            {
                value++;
                MPI_Ssend(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
            }
            else
            {
                printf("Final binary value: %d%d%d\n", (value >> 2) & 1, (value >> 1) & 1, value & 1);
                MPI_Finalize();
                MPI_Abort(MPI_COMM_WORLD, 0);
                break;
            }
        }
    }

    // process 1 increments value by 1 and sends to process 2
    if (rank == 1)
    {
        while (1)
        {
            MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
            if (value < 7)
            {
                value++;
                MPI_Ssend(&value, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
            }
            else
            {
                printf("Final binary value: %d%d%d\n", (value >> 2) & 1, (value >> 1) & 1, value & 1);
                MPI_Finalize();
                MPI_Abort(MPI_COMM_WORLD, 0);
                break;
            }
        }
    }

    // process 2 increments value by 1 and sends to process 0
    if (rank == 2)
    {
        while (1)
        {
            MPI_Recv(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
            if (value < 7)
            {
                value++;
                MPI_Ssend(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            }
            else
            {
                printf("Final binary value: %d%d%d\n", (value >> 2) & 1, (value >> 1) & 1, value & 1);
                MPI_Finalize();
                MPI_Abort(MPI_COMM_WORLD, 0);
                break;
            }
        }
    }

    MPI_Finalize();
    return 0;
}
