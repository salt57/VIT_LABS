#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ARR_SIZE 1200000000
int a[ARR_SIZE];

int main(int argc, char const *argv[])
{
    // generate random array of ARR_SIZE
    for (int i = 0; i < ARR_SIZE; i++)
    {
        a[i] = rand() % ARR_SIZE;
    }
    
    printf("Sourish Gupta - 20BCE0453\n\n\n");

#pragma omp parallel sections
    {
#pragma omp section
        {
            double t1, t2;
            t1 = omp_get_wtime();
            int min = a[0];
            for (int i = 1; i < ARR_SIZE; i++)
            {
                if (a[i] < min)
                    min = a[i];
            }
            t2 = omp_get_wtime();
            printf("Min = %d \ntime = %f start time = %f\n\n", min, (t2 - t1), t1);
        }
#pragma omp section
        {
            double t1, t2;
            t1 = omp_get_wtime();
            int max = a[0];
            for (int i = 1; i < ARR_SIZE; i++)
            {
                if (a[i] > max)
                    max = a[i];
            }
            t2 = omp_get_wtime();
            printf("Max = %d \ntime = %f start time= %f\n\n", max, (t2 - t1), t1);
        }
    }
    return 0;
}
