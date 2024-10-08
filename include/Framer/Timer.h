#pragma once
#include <chrono>

namespace fr {
    class Timer
    {
    private:
        float* m_diff;
        float* m_FPS;

        std::chrono::steady_clock::time_point start;

    public:
        Timer(float* diff, float* FPS);
        ~Timer();

    };
}