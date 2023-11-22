#ifndef OPTIMALSCHEDULING_H
#define OPTIMALSCHEDULING_H

#include <vector>
#include <string>
#include <limits.h>
#include <chrono>

using namespace std;

// optimalscheduling.cpp

/**
 * @brief the optimal scheduling class
 * 
 */
class Optimal {
public:
    /**
     * @brief Constructor of optimal scheduling class
     * 
     * @param time Task time array
     * @param n Number of tasks
     * @param k Number of machines
     */
    Optimal(vector<int> time, int n, int k) {
        this->n = n;
        this->k = k;
        this->cost = INT_MAX;
        this->Time = time;
        this->match = vector<int>(n, -1);
        this->bestmatch = vector<int>(n, -1);
        this->current = vector<int>(k, 0);
    }
    ~Optimal() {}
    /**
     * @brief Optimal scheduling algorithm subfunction
     * 
     * @param i level of backtracking
     */
    void optimalschedulingsub(int i);
    /**
     * @brief Get optimal scheduling
     * 
     */
    void optimalscheduling();
    // cost of optimal scheduling
    int cost;
    // best match of optimal scheduling
    vector<int> bestmatch;

private:
    // number of tasks
    int n;
    // number of machines
    int k;
    // task-machine match
    vector<int> match;
    // current time of each machine
    vector<int> current;
    // task time array
    vector<int> Time;
};

// rw.cpp

/**
 * @brief Read file
 * 
 * @param filename File name
 * @param nums Task time array
 * @return int Number of machines
 */
int readfile(string filename, vector<int> &nums);

// timer.cpp

/**
 * @brief timer for performance test
 * 
 */
class Timer {
public:
    /**
     * @brief Construct a new Timer object
     * 
     */
    Timer() : start_(chrono::high_resolution_clock::now()) {}
    ~Timer() {}
    /**
     * @brief Reset timer
     * 
     */
    void reset();
    /**
     * @brief Get elapsed time
     * 
     * @return Elapsed time in microseconds(us)
     */
    double elapsed() const;

private:
    // start time
    chrono::time_point<chrono::high_resolution_clock> start_;
};

#endif // OPTIMALSCHEDULING_H