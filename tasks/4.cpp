#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void four()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int max = 1000;
    int min = -1000;

    #pragma omp parallel num_threads(2)
    {
        if (omp_get_thread_num() == 0) {
            for (int e : a) {
                if(e < max) {
                    max = e;
                }
            }
        }

        else if (omp_get_thread_num() == 1) {
            for (int e : b) {
                if(e > min) {
                    min = e;
                }
            }
        }
    }

    printf("MAX %d MIN %d", min, max);
}
#pragma clang diagnostic pop

