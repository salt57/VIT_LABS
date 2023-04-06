#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MAX_N 10000

int main(int argc, char** argv) {
    int rank, size, n, i;
    int biggest = 0;
    int nums[MAX_N];
    int buf[MAX_N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
        char *buff;
    int buf_size;
    MPI_Buffer_attach(malloc(MAX_N), MAX_N);

    if (rank == 0) {
        printf("Sourish Gupta - 20BCE0453\n\n");
        printf("Enter the number of integers to compare: ");
        scanf("%d", &n);

        if (n > MAX_N) {
            printf("Error: too many integers, maximum is %d\n", MAX_N);
            MPI_Finalize();
            return 1;
        }

        printf("Enter %d integers: ", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        for (i = 1; i < size; i++) {
            MPI_Bsend(nums, n, MPI_INT, i, 0, MPI_COMM_WORLD);
        }

        for (i = 0; i < n; i++) {
            if (nums[i] > biggest) {
                biggest = nums[i];
            }
        }
    } else {
        MPI_Recv(buf, MAX_N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        for (i = 0; i < MAX_N; i++) {
            if (buf[i] > biggest) {
                biggest = buf[i];
            }
        }
    }

    int global_biggest;
    MPI_Reduce(&biggest, &global_biggest, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("The biggest integer is: %d\n", global_biggest);
    }

        MPI_Buffer_detach(&buff, &buf_size);
    MPI_Finalize();

    return 0;
}

