#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void second()
{
    int n = 3;
    omp_set_num_threads(3);
#pragma omp parallel if(n > 2)
    {
        printf("Tread(%d) of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }

    omp_set_num_threads(2);
#pragma omp parallel if(n > 2)
    {
        printf("Tread(%d) of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
}
#pragma clang diagnostic pop

