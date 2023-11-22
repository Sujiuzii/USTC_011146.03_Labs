#include"quicksort.h"
#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>

using namespace std;

Quicksort::Quicksort(int len, vector<int> &A){
    Arr = A;
    length = len;
}

Quicksort::~Quicksort(){}

int
Quicksort::Partition(int p, int r, int pivotindex)
{
    int pivot = Arr[pivotindex];
    swap(Arr[r], Arr[pivotindex]);
    int i = p-1;
    for (int j=p; j<r; ++j){
        if(Arr[j] <= pivot){
            ++i;
            swap(Arr[i], Arr[j]);
        }
    }
    swap(Arr[i+1], Arr[r]);
    return i+1;
}

void
Quicksort::InsertSort(int p, int r)
{
    int tmp;
    for (int i=p+1; i<=r; ++i){
        tmp = Arr[i];
        for (int j=i-1; j>=p; --j){
            if(Arr[j] <= tmp){
                if(i != j+1){
                    Arr[j+1] = tmp;
                }
                break;
            }
            Arr[j+1] = Arr[j];
        }
    }
}

void
Quicksort::SimpleQuickSort_Sub(int p, int r)
{
    if(p < r){
        int q = Partition(p, r, r);
        SimpleQuickSort_Sub(p, q-1);
        SimpleQuickSort_Sub(q+1, r);
    }
}

void
Quicksort::SimpleQuickSort()
{
    SimpleQuickSort_Sub(0, length-1);
}

void
Quicksort::GatherPartition(int p, int r, int pivotindex)
{
    int pivot = Arr[pivotindex];
    swap(Arr[r], Arr[pivotindex]);
    int ecount = 0;
    int i = p-1;
    int j = p;
    while(j < r - ecount){
        if(Arr[j] == pivot){
            ++ecount;
            swap(Arr[j], Arr[r-ecount]);
        }
        if(Arr[j] < pivot){
            ++i;
            swap(Arr[j], Arr[i]);
        }
        ++j;
    }

    int k = i+1;
    for(j=0; j <= ecount; ++k, ++j){
        Arr[r-j] = Arr[k];
        Arr[k] = pivot;
    }
    Pgather.push(i+1);
    Pgather.push(i+1+ecount);
}

int
Quicksort::RandomPartition(int p, int r)
{
    int randompivot = p + rand() % (r - p + 1);
    return Partition(p, r, randompivot);
}

void
Quicksort::RandomPivot_Sub(int p, int r)
{
    if(p < r){
        int q = RandomPartition(p, r);
        RandomPivot_Sub(p, q-1);
        RandomPivot_Sub(q+1, r);
    }
}

void
Quicksort::RandomPivot()
{
    srand(seed);
    RandomPivot_Sub(0, length-1);
}

void
Quicksort::SetSeed(int s)
{
    seed = s;
}

void
Quicksort::QuickInsertSort_Sub(int p, int r, int k)
{
    if(k < r - p){
        int q = Partition(p, r, MedianofThree(p, r));
        QuickInsertSort_Sub(p, q-1, k);
        QuickInsertSort_Sub(q+1, r, k);
    }
    else{
        InsertSort(p, r);
    }
}

void
Quicksort::QuickInsertSort(int k)
{
    QuickInsertSort_Sub(0, length - 1, k);
}

int
Quicksort::MedianofThree(int left, int right)
{
    if(left == right) return left;
    int mid = left + (right - left)/2;
    if(Arr[left] < Arr[mid]){
        if(Arr[mid] < Arr[right]){
            return mid;
        }
        else{
            if(Arr[left] < Arr[right]){
                return right;
            }
            else return left;
        }
    }
    else{
        if(Arr[mid] > Arr[right]){
            return mid;
        }
        else{
            if(Arr[left] < Arr[right]){
                return left;
            }
            else return right;
        }
    }
}

int
Quicksort::PartitionMOT(int p, int r)
{
    int pivot = MedianofThree(p, r);
    return Partition(p, r, pivot);
}

void
Quicksort::MOTSort_Sub(int p, int r)
{
    if(p < r){
        int q = PartitionMOT(p, r);
        MOTSort_Sub(p, q-1);
        MOTSort_Sub(q+1, r);
    }
}

void
Quicksort::MOTSort()
{
    MOTSort_Sub(0, length-1);
}

void
Quicksort::GatherSort_Sub(int p, int r)
{
    if(p < r){
        GatherPartition(p, r, MedianofThree(p, r));
        GatherSort_Sub(Pgather.top()+1, r);
        Pgather.pop();
        GatherSort_Sub(p, Pgather.top()-1);
        Pgather.pop();
    }
}

void
Quicksort::GatherSort()
{
    GatherSort_Sub(0, length-1);
}

void
Quicksort::Print()
{
    for (int i=0; i<length; ++i){
        cout << Arr[i] << ' ';
    }
    cout << endl;
}

void
Quicksort::Sort_Sub(int p, int r, int k)
{
    if(k < r - p){
        GatherPartition(p, r, MedianofThree(p, r));
        QuickInsertSort_Sub(p, Pgather.top()-1, k);
        Pgather.pop();
        QuickInsertSort_Sub(Pgather.top()+1, r, k);
        Pgather.pop();
    }
    else{
        InsertSort(p, r);
    }
}

void
Quicksort::Sort(int k)
{
    Sort_Sub(0, length - 1, k);
}
