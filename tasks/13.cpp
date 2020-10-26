#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
#include <iostream>
#include <omp.h>
#include <unistd.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"

void first_v() {
    int threadNum = 8;
#pragma omp parallel num_threads(8)
    {
        if (omp_get_thread_num() < threadNum) {
            sleep(threadNum - omp_get_thread_num());
            printf("Tread(%d) of %d Hello world\n", omp_get_thread_num(), omp_get_num_threads());
            threadNum --;
        }
    }
}

void second_v() {
#pragma omp parallel num_threads(8)
    {
        int nthreads = omp_get_num_threads();
        for(int i=nthreads-1; i>=0; i--)
        {
#pragma omp barrier
            {
                if(i==omp_get_thread_num())
                {
                    printf("Tread(%d) of %d Hello world\n", omp_get_thread_num(), omp_get_num_threads());
                }
            }
        }
    }
}
    omp_lock_t simple_lock;
void third_v() {
    omp_init_lock(&simple_lock);
    int threadNum = 7;
#pragma omp parallel num_threads(8) shared(threadNum)
    {
//        omp_set_lock(&simple_lock);
//        for(int i=omp_get_num_threads()-1; i>=0; i--)
//        {

                if (omp_get_thread_num() != threadNum)
                {
                    omp_set_lock(&simple_lock);
                } else {
                    printf("Tread(%d) of %d Hello world\n", omp_get_thread_num(), omp_get_num_threads());
                    threadNum --;
                    omp_unset_lock(&simple_lock);
                }
//            omp_unset_lock(&simple_lock);
//        }

    }
    omp_destroy_lock(&simple_lock);
}

void thirteen() {
    first_v();
//second_v();
//    third_v();
}

#pragma clang diagnostic pop