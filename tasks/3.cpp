#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void third()
{
    int a = 2;
    int b = 4;
    printf("A is %d, B is %d\n", a, b);

    #pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        a += omp_get_thread_num();
        b += omp_get_thread_num();
        printf("A is %d, B is %d\n", a, b);
    };
    printf("A is %d, B is %d\n", a, b);

    #pragma omp parallel num_threads(4) shared(a) private(b)
    {
        a -= omp_get_thread_num();
        b -= omp_get_thread_num();
        printf("A is %d, B is %d\n", a, b);
    };
    printf("A is %d, B is %d\n", a, b);
}
#pragma clang diagnostic pop
