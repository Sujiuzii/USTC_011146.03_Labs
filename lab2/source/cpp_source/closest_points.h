#ifndef CLOSEST_POINTS_H
#define CLOSEST_POINTS_H

#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

struct Coordinate{
    int index;
    float x;
    float y;
};

struct Pair{
    Coordinate A;
    Coordinate B;
    float distance;
};


class ClosestPoints
{
private:
    Pair closest;
public:
    vector<Coordinate> Coordinates;
    vector<Coordinate> XSort;
    vector<Coordinate> YSort;
    ClosestPoints();
    ~ClosestPoints();
    void ReadFile(string filename);
    void Bruteforce(void);
    void SortCoordinate(void);
    Pair Divide_Sub(vector<Coordinate> X, vector<Coordinate> Y);
    Pair Combine(vector<Coordinate> Yl, vector<Coordinate> Yr, float pivot, Pair p);
    void Divide(void);
    void PrintClosest(void);
};

class Timer
{
private:
    chrono::time_point<chrono::high_resolution_clock> start_time;
    chrono::time_point<chrono::high_resolution_clock> end_time;

public:
    Timer();
    ~Timer();
    void start();
    void stop();
    double elapsedMilliseconds();
};


#endif