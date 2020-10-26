#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void five() {
    int arr[6][8];
    srand(time(NULL));
    #pragma omp for
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = rand() % 21;
        }
    }

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    sum += j;
                }
            }
            printf("Srednee arifmeticheskoe %d, \n", sum / 48);
            printf ("1 Tread %d\n", omp_get_thread_num());
        }
        #pragma omp section
        {
            int max = 1000;
            int min = -1000;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (arr[i][j] < max)
                        max = arr[i][j];
                    if (arr[i][j] > min)
                        min = arr[i][j];
                }
            }
            printf ("MAX: %d, MIN: %d\n", min, max);
            printf ("2 Tread %d\n", omp_get_thread_num());
        }
        #pragma omp section
        {
            int num = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (arr[i][j] % 3 == 0) {
                        num++;
                    }
                }
            }
            printf ("Result : %d\n", num);
            printf ("3 Tread %d\n", omp_get_thread_num());
        }
    }
}
#pragma clang diagnostic pop
