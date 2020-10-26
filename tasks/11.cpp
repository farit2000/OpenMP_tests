#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void eleven() {
    const int N = 30;
    int count = 0;
    int vector[N]; // вектор
    srand(time(NULL));
    // заполнение вектора
    for (int ix = 0; ix < N; ix++ )
    {
        vector[ix] = rand() % 21 - 10;
    }
#pragma omp parallel for
    for (int i = 0 ; i < N; ++i )
    {
        if (vector[i] % 9 == 0)
        #pragma omp atomic
            count++;
    }
    for (int ix = 0; ix < N; ix++ )
    {
        cout << vector[ix] << " ";
    }
    cout << "\n";
    printf("Result : %d", count);
}
#pragma clang diagnostic pop