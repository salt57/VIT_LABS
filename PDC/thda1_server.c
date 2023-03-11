#include <stdio.h>
#include <mpi.h>

// simple remote procedure to square an integer
void remote_procedure(int *input, int *output)
{
    *output = (*input) * (*input);
}

int main(int argc, char **argv)
{
    printf("Sourish Gupta - 20BCE0453\n");
    // MPI initialization
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Server process
    if (rank == 0)
    {
        // define required variables
        int input, output;
        MPI_Status status;

        // keep ;istening for messages unless shutdown recieved
        while (1)
        {
            // recieve the input and the tag and decide course of action based on tag value
            MPI_Recv(&input, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

            // RPC request
            if (status.MPI_TAG == 1)
            {
                printf("\nRPC request received\n");
                remote_procedure(&input, &output);
                MPI_Send(&output, 1, MPI_INT, status.MPI_SOURCE, 2, MPI_COMM_WORLD);
            }

            // Shutdown request
            else if (status.MPI_TAG == 2)
            {
                printf("\nserver shutdown signal received\n");
                break;
            }
        }
    }
    MPI_Finalize();
    return 0;
}