#include <iostream>
#include <omp.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void twelve() {
    const int N = 50;
    int max = 0;
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
#pragma omp critical
        {
            if (vector[i] > max && vector[i] % 7 == 0) max = vector[i];
        }
    }

    for (int ix = 0; ix < N; ix++ )
    {
        cout << vector[ix] << " ";
    }
    cout << "\n";
    printf("Result : %d", max);}
#pragma clang diagnostic pop

