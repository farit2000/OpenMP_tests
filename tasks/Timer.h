#ifndef OPENMP_TEST_TIMER_H
#define OPENMP_TEST_TIMER_H
#include <string>
#include <chrono>

class Timer {
    private:
        using clock_t = std::chrono::high_resolution_clock;
        using second_t = std::chrono::duration<double, std::ratio<1> >;

        std::chrono::time_point<clock_t> m_beg;

    public:
//        Timer() : m_beg(clock_t::now())
//        {
//        }
        void reset();
        double elapsed() const;
};


#endif //OPENMP_TEST_TIMER_H


