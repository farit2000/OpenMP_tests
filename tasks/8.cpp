#include <iostream>
#include <omp.h>
#include <chrono>
#include "Timer.h"


class timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
void eight() {
    double a[1600];
    double bStatic[1600];
    timer t;
//    #pragma omp parallel for
    for (int i = 0; i < 1600; i++)
        a[i] = i;
    printf("%f\n", t.elapsed());
    std::fill(std::begin(a), std::end(a),0);
    t.reset();
#pragma omp parallel for num_threads(8) schedule (static)
    for (int i = 1; i < 1599; i++) {
        bStatic[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }
    printf("Static : %f\n", t.elapsed());
    std::fill(std::begin(a), std::end(a),0);
    t.reset();
#pragma omp parallel for num_threads(8) schedule (dynamic)
    for (int i = 1; i < 1599; i++) {
        bStatic[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }
    printf("Dynamic : %f\n", t.elapsed());
    std::fill(std::begin(a), std::end(a),0);
    t.reset();
#pragma omp parallel for num_threads(8) schedule (guided)
    for (int i = 1; i < 1599; i++) {
        bStatic[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }
    printf("Guided : %f\n", t.elapsed());
    std::fill(std::begin(a), std::end(a),0);
    t.reset();
#pragma omp parallel for num_threads(8) schedule (auto)
    for (int i = 1; i < 1599; i++) {
        bStatic[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }
    printf("Auto : %f\n", t.elapsed());
}
#pragma clang diagnostic pop