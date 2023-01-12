#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 500

int main(int argc, char const *argv[])
{
    printf("Sourish Gupta - 20BCE0453\n\n");
    int tid, numt;
    int i, j, k;
    double ts1, ts2, tp1, tp2;
    int a[N][N], b[N][N], c[N][N];
    // generate NxN random matrix in parallel
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
            c[i][j] = 0;
        }
    }

    tp1 = omp_get_wtime();

    #pragma omp parallel for private(i, j, k) shared(a, b, c)
        for (i = 0; i < N; ++i)
        {
            for (j = 0; j < N; ++j)
            {
                for (k = 0; k < N; ++k)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    tp2 = omp_get_wtime();

    ts1 = omp_get_wtime();
    for (i = 0; i < N; ++i)
        {
            for (j = 0; j < N; ++j)
            {
                for (k = 0; k < N; ++k)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    ts2 = omp_get_wtime();
    
    printf("Serial Time=%g\n", (ts2 - ts1));
    printf("Parallel Time=%g\n", (tp2-tp1));
    return 0;
}