#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// check if number is prime
int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    printf("Sourish Gupta - 20BCE0453\n\n");
    int N, i, tid, numt, count = 0;
    double t1, t2;
    printf("Enter the number of elements N: ");
    scanf("%d", &N);
    t1 = omp_get_wtime();

#pragma omp parallel for default(shared) reduction(+ \
                                                   : count)
    for (i = 1; i <= N; i++)
    {
        if (isPrime(i) == 1)
            count += 1;
    }
    t2 = omp_get_wtime();
    printf("Count = %d. Time=%g\n", count, (t2 - t1));
}
