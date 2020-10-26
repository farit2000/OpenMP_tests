#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void seven() {
    int a[12];
    int b[12];
    int c[12];
    #pragma omp parallel for num_threads(3) schedule (static, 4)
    for (int i=0; i<12; i++ )
    {
        a[i] = i;
        b[i] = i;
        printf("a[i]=%d, b[i]=%d, threads=%d, tread_id=%d\n", a[i], b[i], omp_get_num_threads(), omp_get_thread_num());
    }

    #pragma omp parallel for num_threads(4) schedule (dynamic, 3)
    for (int i=0; i<12; i++ )
    {
        c[i] = a[i] + b[i];
        printf("c[i]=%d, threads=%d, tread_id=%d\n", c[i], omp_get_num_threads(), omp_get_thread_num());
    }
}
#pragma clang diagnostic pop

