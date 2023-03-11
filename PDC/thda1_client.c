#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    // MPI initialization
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // client process
    if (rank == 1)
    {
        // set input and define output
        int input = 5, output;

        // send the input to server
        MPI_Send(&input, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);

        // recieve the output from server and print it
        MPI_Recv(&output, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("\nRemote procedure output: %d\n", output);
        
        // Shutdown the server
        int dummy = 0;
        MPI_Send(&dummy, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}