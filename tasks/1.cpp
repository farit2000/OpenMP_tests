#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void first() {
    #pragma omp parallel num_threads(8)
    {
        printf("Tread(%d) of %d Hello world\n", omp_get_thread_num(), omp_get_num_threads());
    }
}
#pragma clang diagnostic pop

