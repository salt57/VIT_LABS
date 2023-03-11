#include <stdio.h>
#include <omp.h>

int global_var = 0;

#pragma omp threadprivate(global_var)

int main() {
    printf("Sourish gupta - 20BCE0453\n");
    int i;

    #pragma omp parallel
    {
        // Set the value of global_var to the thread ID
        global_var = omp_get_thread_num();

        // Set i to the thread ID
        #pragma omp single
        i = omp_get_thread_num();

        // Print the value of global_var and i for each thread
        #pragma omp critical
        printf("Thread %d: global_var = %d, i = %d\n", omp_get_thread_num(), global_var, i);

        // Increment global_var and i by 1
        global_var++;
        i++;

        // Use a barrier to make sure all threads have finished incrementing
        #pragma omp barrier

        // Print the updated value of global_var and i for each thread
        #pragma omp critical
        printf("Thread %d: global_var = %d, i = %d\n", omp_get_thread_num(), global_var, i);

        // Use lastprivate to save the final value of i to the master thread
        #pragma omp for lastprivate(i)
        for (int j = 0; j < 10; j++) {
            i = j;
            printf("Thread %d: i = %d\n", omp_get_thread_num(), i);
        }
    }

    // Print the final value of i for the master thread
    printf("Master thread: i = %d\n", i);

    return 0;
}