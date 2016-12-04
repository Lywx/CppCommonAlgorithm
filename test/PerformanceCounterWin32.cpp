#include "PerformanceCounter.h"

#include <stdexcept>
#include <string>

#include <windows.h>

/************************************************************************/
/* Platform Dependent Implementation                                    */
/************************************************************************/
class PerformanceCounterImp
{
public:
    PerformanceCounterImp()
    {
        if (!CounterInitialized)
        {
            QueryPerformanceFrequency(&CounterFrequency);
            CounterInitialized = true;
        }
    }

    double GetMilliseconds() const
    {
        LARGE_INTEGER counter;
        QueryPerformanceCounter(&counter);

        // Millisecond: 1000    * counter / frequency / 1
        // Microsecond: 1000000 * counter / frequency / 1
        return MillisecondsPeriod::den * double(counter.QuadPart) / double(CounterFrequency.QuadPart) / MillisecondsPeriod::num;
    }

private:
    typedef std::chrono::milliseconds Milliseconds;
    typedef Milliseconds::period      MillisecondsPeriod;

    static bool CounterInitialized;
    static LARGE_INTEGER CounterFrequency;
};

bool          PerformanceCounterImp::CounterInitialized = false;
LARGE_INTEGER PerformanceCounterImp::CounterFrequency;

/************************************************************************/
/* Constructors and Destructor                                          */
/************************************************************************/
PerformanceCounter::PerformanceCounter()
    : m_initializationPoint(std::chrono::steady_clock::now())
    , m_implementation(std::make_shared<PerformanceCounterImp>(PerformanceCounterImp()))
{
}

PerformanceCounter::PerformanceCounter(const PerformanceCounter& rhs)
    : m_initializationPoint(rhs.m_initializationPoint)
    , m_implementation(rhs.m_implementation)
{
}

PerformanceCounter& PerformanceCounter::operator=(const PerformanceCounter& rhs)
{
    m_implementation = rhs.m_implementation;
    m_initializationPoint = rhs.m_initializationPoint;

    return *this;
}

PerformanceCounter::PerformanceCounter(PerformanceCounter&& rhs) noexcept
    : m_initializationPoint(rhs.m_initializationPoint)
    , m_implementation(rhs.m_implementation)
{
    rhs.m_implementation = nullptr;
}

PerformanceCounter& PerformanceCounter::operator=(PerformanceCounter&& rhs) noexcept
{
    if (this != &rhs)
    {
        m_implementation = rhs.m_implementation;
        m_initializationPoint = rhs.m_initializationPoint;

        rhs.m_implementation = nullptr;
    }

    return *this;
}

PerformanceCounter::~PerformanceCounter()
{
}

/************************************************************************/
/* Public Members                                                       */
/************************************************************************/
double PerformanceCounter::GetMilliseconds() const
{
    return m_implementation->GetMilliseconds();
}