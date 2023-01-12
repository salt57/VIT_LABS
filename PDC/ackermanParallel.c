#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

// ackerman recursive function in omp parallel
int ack(int m, int n)
{
    int result, presult;
    if (m == 0)
    {
        result = n + 1;
    }
    else if (n == 0)
    {
        result = ack(m - 1, 1);
    }
    else
    {
#pragma parallel shared(result, presult) private(m, n)
        {
#pragma omp task shared(presult)
            {
                presult = ack(m, n - 1);
            }
#pragma omp taskwait
            result = ack(m - 1, presult);
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    printf("%d ", ack(50, 60));

    return 0;
}
