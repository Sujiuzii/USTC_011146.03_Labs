#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

class Quicksort
{
private:
    int seed = 47;
public:
    stack<int> Pgather;
    int length;
    vector<int> Arr;
    Quicksort(int len, vector<int> &A);
    ~Quicksort();
    int Partition(int p, int r, int pivotindex);
    int MedianofThree(int left, int right);
    int PartitionMOT(int p, int r);
    void MOTSort();
    void MOTSort_Sub(int p, int r);
    void SimpleQuickSort_Sub(int p, int r);
    void SimpleQuickSort(void);
    void RandomPivot_Sub(int p, int r);
    void RandomPivot(void);
    int RandomPartition(int p, int r);
    void GatherPartition(int p, int r, int pivotindex);
    void InsertSort(int p, int r);
    void QuickInsertSort_Sub(int p, int q, int k);
    void QuickInsertSort(int k);
    void GatherSort_Sub(int p, int r);
    void GatherSort(void);
    void SetSeed(int s);
    void Print(void);
    void Sort_Sub(int p, int q, int k);
    void Sort(int k);
};

vector<int> ReadArr(string filename);
void WriteArr(vector<int> &Arr, string filename);

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