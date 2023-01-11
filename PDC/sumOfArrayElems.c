// calculate sum of elements in an array - sequential code

#include <omp.h>
#include <stdio.h>

#define ARR_SIZE 1200000000
int a[ARR_SIZE];

//Sequential code:
// int main(int argc, char const *argv[])
// {
//     int i, sum = 0;
//     double t1,t2;
//     for( i=0; i<ARR_SIZE; i++) {
//         a[i] = 1;
//     }
//     t1 = omp_get_wtime();
//     for( i=0; i<ARR_SIZE; i++) {
//         sum += a[i];
//     }
//     t2 = omp_get_wtime();
//     printf("Sum of the array elements = %d. Time=%g\n", sum, t2-t1);
//     return 0;
// }

//Parallel code:
int main(int argc, char const *argv[])
{
    int i, sum=0, tid, numt;
    double t1,t2;
    for( i=0; i<ARR_SIZE; i++) {
        a[i] = 1;
    }
    t1 = omp_get_wtime();
    #pragma omp parallel default(shared) private(i,tid)
    {
        int from,to, psum=0;
        tid = omp_get_thread_num();
        numt = omp_get_num_threads();
        from = tid * (ARR_SIZE/numt);
        to = (tid+1) * (ARR_SIZE/numt) -1;
        if(tid == numt-1)
            to = ARR_SIZE-1;
        printf("Hello from %d of %d, my range is from %d to %d\n", tid, numt, from, to);
        for( i=from; i<=to; i++) {
            psum += a[i];
        }
        #pragma omp critical
            sum += psum;
    }
    t2 = omp_get_wtime();
    printf("Sum of the array elements = %d. Time=%g\n", sum, t2-t1);
    return 0;
}
