#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void six() {
    int arr[100];
    srand(time(NULL));
    for(auto & item : arr)
        item = rand() % 21;
    int sumr = 0;
    int sum = 0;

    #pragma omp parallel for reduction(+:sumr)
    for (int i=0; i < 100; i++)
        sumr = sumr + arr[i];

    #pragma omp parallel for
    for (int i=0; i < 100; i++)
        sum = sum + arr[i];

    printf("%d\n", sumr / (sizeof(arr)/sizeof(arr[0])));
    printf("%d\n", sum / (sizeof(arr)/sizeof(arr[0])));
}
#pragma clang diagnostic pop