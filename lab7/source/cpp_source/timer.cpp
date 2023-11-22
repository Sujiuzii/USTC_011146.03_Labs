#include "optimalscheduling.h"
#include <chrono>

using namespace std;

void
Timer::reset() {
    start_ = std::chrono::high_resolution_clock::now();
}

double
Timer::elapsed() const {
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start_).count();
}
