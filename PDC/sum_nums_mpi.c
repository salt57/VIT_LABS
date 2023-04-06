#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define N 100

int main(int argc, char **argv)
{

    int size, rank;
    int numbers[N], numbers2[N], numbers3[N], sum = 0, sum2 = 0, sum3 = 0, half_sum = 0, half_sum2 =0, half_sum3 = 0;
    double start, end;

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Sourish Gupta - 20BCE0453\n\n");
        // Generate random numbers
        for (int i = 0; i < N; i++)
        {
            numbers[i] = rand() % 10;
            if(i>=N/2)
                sum += numbers[i];
        }

        // Send half of the numbers to process 1 using standard send
        start = MPI_Wtime();
        MPI_Send(&numbers, N / 2, MPI_INT, 1, 0, MPI_COMM_WORLD);

        // Receive the sum of the other half of the numbers from process 1
        MPI_Recv(&half_sum, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        end = MPI_Wtime();
        printf("Standard send time: %f\n", end - start);

        // Add the half sum to the total sum and print the result
        sum += half_sum;
        printf("Total sum: %d\n", sum);
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += numbers[i];
        }
        printf("actual calculated sum: %d\n\n", sum);

        // Generate random numbers
        for (int i = 0; i < N; i++)
        {
            numbers2[i] = rand() % 10;
            if(i>=N/2)
                sum2 += numbers2[i];
        }

        start = MPI_Wtime();
        MPI_Ssend(&numbers2, N / 2, MPI_INT, 1, 0, MPI_COMM_WORLD);

        MPI_Recv(&half_sum2, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        end = MPI_Wtime();
        printf("Synchronized send time: %f\n", end - start);

        // Add the half sum to the total sum and print the result
        sum2 += half_sum2;
        printf("Total sum: %d\n", sum2);
        sum2 = 0;
        for (int i = 0; i < N; i++)
        {
            sum2 += numbers2[i];
        }
        printf("actual calculated sum: %d\n\n", sum2);

        // Generate random numbers
        for (int i = 0; i < N; i++)
        {
            numbers3[i] = rand() % 10;
            if(i>=N/2)
                sum3 += numbers3[i];
        }

        start = MPI_Wtime();
        MPI_Rsend(&numbers3, N / 2, MPI_INT, 1, 0, MPI_COMM_WORLD);

        MPI_Recv(&half_sum3, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        end = MPI_Wtime();
        printf("Ready send time: %f\n", end - start);

        // Add the half sum to the total sum and print the result
        sum3 += half_sum3;
        printf("Total sum: %d\n", sum3);
        sum3 = 0;
        for (int i = 0; i < N; i++)
        {
            sum3 += numbers3[i];
        }
        printf("actual calculated sum: %d\n", sum3);
    }
    else if (rank == 1)
    {
        // Receive half of the numbers from process 0 using standard receive
        int received[N / 2];
        MPI_Recv(&received, N / 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        // Compute the sum of the received numbers
        for (int i = 0; i < N / 2; i++)
        {
            half_sum += received[i];
        }

        // Send the half sum back to process 0 using ready send
        MPI_Send(&half_sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

        MPI_Recv(&received, N / 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        // Compute the sum of the received numbers
        for (int i = 0; i < N / 2; i++)
        {
            half_sum2 += received[i];
        }

        // Send the half sum back to process 0 using ready send
        MPI_Ssend(&half_sum2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

        MPI_Recv(&received, N / 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        // Compute the sum of the received numbers
        for (int i = 0; i < N / 2; i++)
        {
            half_sum3 += received[i];
        }

        // Send the half sum back to process 0 using ready send
        MPI_Rsend(&half_sum3, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}