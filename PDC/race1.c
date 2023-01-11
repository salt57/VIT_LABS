#include <omp.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    #pragma omp parallel
    {
        int numt = omp_get_num_threads();
        int tid = omp_get_thread_num();
        printf("Hello from thread %d of %d\n", tid, numt);
    }
    return 0;
}