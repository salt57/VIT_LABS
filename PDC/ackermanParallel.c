#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

// ackerman recursive function in omp parallel
int ack(int m, int n)
{
    int result, presult;
#pragma parallel shared(result, presult) private(m, n)
    {
        if (m == 0)
        {
            result = n + 1;
        }
        else if (n == 0)
        {
#pragma omp task shared(result)
            {
                result = ack(m - 1, 1);
            }
        }
        else
        {
#pragma omp task shared(presult)
            {
                presult = ack(m, n - 1);
            }

#pragma omp taskwait
            {
                result = ack(m - 1, presult);
            }
        }
    }
    return result;
}

int ackSeq(int m, int n)
{
    int result, presult;
    if (m == 0)
    {
        result = n + 1;
    }
    else if (n == 0)
    {
        result = ackSeq(m - 1, 1);
    }
    else
    {
        result = ackSeq(m - 1, ackSeq(m, n - 1));
    }
    return result;
}

int main(int argc, char const *argv[])
{
    printf("Sourish Gupta - 20BCE0453\n\n");
    omp_set_num_threads(4);
    double t1, t2, s1, s2;
    t1 = omp_get_wtime();
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            printf("%d\n", ack(i, j));
        }
    }
    t2 = omp_get_wtime();
    printf("parallel time = %g", (t2 - t1));
    s1 = omp_get_wtime();
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            printf("%d\n", ackSeq(i, j));
        }
    }
    s2 = omp_get_wtime();
    printf("sequential time = %g", (s2 - s1));

    return 0;
}
