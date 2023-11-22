#include <iostream>
#include <chrono>
#include"quicksort.h"

using namespace std;

Timer::Timer(){}

Timer::~Timer(){}

void
Timer::start()
{
    start_time = chrono::high_resolution_clock::now();
}

void
Timer::stop()
{
    end_time = chrono::high_resolution_clock::now();
}

double
Timer::elapsedMilliseconds()
{
    chrono::duration<double, milli> elapsed = end_time - start_time;
    return elapsed.count();
}
