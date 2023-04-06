#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 12

int main(int argc, char** argv) {
  int rank, size;
  int array[ARRAY_SIZE] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int local_array[ARRAY_SIZE/4];
  int local_sum = 0, global_sum = 0;
  float average = 0;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(size != 4) {
    printf("This program is designed to run with 4 processes.\n");
    MPI_Finalize();
    exit(1);
  }

  MPI_Scatter(array, ARRAY_SIZE/4, MPI_INT, local_array, ARRAY_SIZE/4, MPI_INT, 0, MPI_COMM_WORLD);

  for(int i=0; i<ARRAY_SIZE/4; i++) {
    local_sum += local_array[i];
  }

  MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  if(rank == 0) {
    average = (float)global_sum / ARRAY_SIZE;
    printf("The average is: %f\n", average);
  }

  MPI_Finalize();
  return 0;
}

