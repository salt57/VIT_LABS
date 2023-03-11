#include <omp.h>
#include <stdio.h>

int main()
{
    omp_set_num_threads(4);
    int a[10];
    int x = 0;
    int i;
#pragma omp parallel private(i) shared(a)
    {
        for (i = 0; i <= 10; i++)
        {
            a[i] = i;
            printf("%d\n", a[i]);
        }
    }

    return 0;
}
