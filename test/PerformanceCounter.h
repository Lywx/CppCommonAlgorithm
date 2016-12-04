#pragma once

#include <chrono>
#include <memory>

class PerformanceCounterImp;
class PerformanceCounter
{
public:
    PerformanceCounter();

    // Copy Operation
    PerformanceCounter(const PerformanceCounter& rhs);
    PerformanceCounter& operator=(const PerformanceCounter& rhs);

    // Move Operation
    PerformanceCounter(PerformanceCounter&& rhs) noexcept;
    PerformanceCounter& operator=(PerformanceCounter&& rhs) noexcept;

    ~PerformanceCounter();

    double GetMilliseconds() const;

private:
    std::chrono::time_point<std::chrono::steady_clock> m_initializationPoint;
    std::shared_ptr<PerformanceCounterImp> m_implementation;
};