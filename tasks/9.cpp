#include <iostream>
#include <omp.h>
#include <iomanip>
//#include "Timer.h"
using namespace std;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void nine() {

    int matrix[1000][1000], // статический массив
    rows    = 0,      // строки
    columns = 0;      // столбцы

    cout << "Введите количество строк матрицы: ";
    cin >> rows;

    cout << "Введите количество столбцов матрицы: ";
    cin >> columns;

    srand(time(NULL));

    // заполнение матрицы
    for (int ix = 0; ix < rows; ix++ )
        for (int jx = 0; jx < columns; jx++)
        {
            matrix[ix][jx] = rand() % 21 - 10;
        }

    int vector[1000]; // вектор

    // заполнение вектора
    for (int ix = 0; ix < columns; ix++ )
    {
        vector[ix] = rand() % 21 - 10;
    }

    int out[1000]; // выходной вектор
    // умножение элементов матрицы на вектор

    //без параллельности
    auto start = chrono::system_clock::now();
    for (int ix = 0; ix < rows; ix++)
    {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++)
            out[ix] += matrix[ix][jx] * vector[jx];
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end - start;
    printf("Without parallel : %f\n", elapsed.count());

    cout << "\nРезультирующий вектор:\n";
    for (int ix = 0; ix < rows; ix++ )
    {
        cout << setw(4) << out[ix] << endl;
    }

    //с параллельностью static
    start = chrono::system_clock::now();
    #pragma omp parallel for num_threads(8) shared(out, matrix, vector) schedule (static)
    for (int ix = 0; ix < rows; ix++)
    {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++)
            out[ix] += matrix[ix][jx] * vector[jx];
    }
    end = chrono::system_clock::now();
    elapsed = end - start;
    printf("With static parallel : %f\n", elapsed.count());


    //с параллельностью dynamic
    start = chrono::system_clock::now();
#pragma omp parallel for num_threads(8) shared(out, matrix, vector) schedule (dynamic)
    for (int ix = 0; ix < rows; ix++)
    {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++)
            out[ix] += matrix[ix][jx] * vector[jx];
    }
    end = chrono::system_clock::now();
    elapsed = end - start;
    printf("With dynamic parallel : %f\n", elapsed.count());

    //с параллельностью guided
    start = chrono::system_clock::now();
#pragma omp parallel for num_threads(8) shared(out, matrix, vector) schedule (guided)
    for (int ix = 0; ix < rows; ix++)
    {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++)
            out[ix] += matrix[ix][jx] * vector[jx];
    }
    end = chrono::system_clock::now();
    elapsed = end - start;
    printf("With guided parallel : %f\n", elapsed.count());

    //с параллельностью auto
    start = chrono::system_clock::now();
#pragma omp parallel for num_threads(8) shared(out, matrix, vector) schedule (auto)
    for (int ix = 0; ix < rows; ix++)
    {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++)
            out[ix] += matrix[ix][jx] * vector[jx];
    }
    end = chrono::system_clock::now();
    elapsed = end - start;
    printf("With auto parallel : %f\n", elapsed.count());

    cout << "\nРезультирующий вектор:\n";
    for (int ix = 0; ix < rows; ix++ )
    {
        cout << setw(4) << out[ix] << endl;
    }
}
#pragma clang diagnostic pop

