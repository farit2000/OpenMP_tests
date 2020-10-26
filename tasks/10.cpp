#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void ten() {
    int d[6][8];
    srand(time(NULL));
#pragma omp for
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            d[i][j] = rand() % 21;
        }
    }
    int max = -1000;
    int min = 1000;
#pragma omp for
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            if (d[i][j] > max || d[i][j] < min)
#pragma omp critical
            {
                if (d[i][j] > max)
                    max = d[i][j];
                if (d[i][j] < min)
                    min = d[i][j];
            }
        }
    }
    printf("Max : %d\n", max);
    printf("Min : %d\n", min);
}
#pragma clang diagnostic pop