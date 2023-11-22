#include"closest_points.h"
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

ClosestPoints::ClosestPoints(){}

ClosestPoints::~ClosestPoints(){}

bool
Xcompare(const Coordinate &a, const Coordinate &b)
{
    return a.x < b.x;
}

bool
Ycompare(const Coordinate &a, const Coordinate &b)
{
    return a.y < b.y;
}

void
ClosestPoints::SortCoordinate()
{
    vector<Coordinate> tmp = Coordinates;
    sort(tmp.begin(), tmp.end(), Xcompare);
    XSort = tmp;
    sort(tmp.begin(), tmp.end(), Ycompare);
    YSort = tmp;
}

float
Distance(Coordinate a, Coordinate b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}


Pair
Closestamong3(vector<Coordinate> X)
{
    Pair c;
    if(X.size() == 2){
        c.distance = Distance(X[0], X[1]);
        c.A = X[0];
        c.B = X[1];
        return c;
    }
    if(Distance(X[0], X[1]) < Distance(X[0], X[2])){
        if(Distance(X[0], X[1]) < Distance(X[1], X[2])){
            c.distance = Distance(X[0], X[1]);
            c.A = X[0];
            c.B = X[1];
        }
        else{
            c.distance = Distance(X[1], X[2]);
            c.A = X[1];
            c.B = X[2];
        }
    }
    else{
        if(Distance(X[0], X[2]) < Distance(X[1], X[2])){
            c.distance = Distance(X[0], X[2]);
            c.A = X[0];
            c.B = X[2];
        }
        else{
            c.distance = Distance(X[1], X[2]);
            c.A = X[1];
            c.B = X[2];
        }
    }
    return c;
}

vector<vector<Coordinate>>
Seperate(vector<Coordinate> Y, float pivot)
{
    vector<vector<Coordinate>> Ypair;
    vector<Coordinate> Yl, Yr;
    for(int i = 0; i < Y.size(); ++i){
        if(Y[i].x <= pivot){
            Yl.push_back(Y[i]);
        }
        else{
            Yr.push_back(Y[i]);
        }
    }
    Ypair.push_back(Yl);
    Ypair.push_back(Yr);
    return Ypair;
}


Pair
ClosestPoints::Divide_Sub(vector<Coordinate> X, vector<Coordinate> Y)
{
    if(X.size() <= 3)
    {
        return Closestamong3(X);
    }
    vector<vector<Coordinate>> Ypair;
    vector<Coordinate> Xl, Xr, Yl, Yr;
    Pair left, right, Winner;
    float pivot = X[X.size()/2 - 1].x;
    for(int i = 0; i < X.size()/2; ++i){
        Xl.push_back(X[i]);
    }
    for(int i = X.size()/2; i < X.size(); ++i){
        Xr.push_back(X[i]);
    }
    Ypair = Seperate(Y, pivot);
    Yl = Ypair[0];
    Yr = Ypair[1];
    left = Divide_Sub(Xl, Yl);
    right = Divide_Sub(Xr, Yr);
    if(left.distance < right.distance){
        Winner = left;
    }
    else{
        Winner = right;
    }
    return Combine(Yl, Yr, pivot, Winner);
}

vector<Coordinate>
CombineSort(vector<Coordinate> A, vector<Coordinate> B)
{
    vector<Coordinate> C;
    int i, j;
    i = j = 0;
    while(i < A.size() || j < B.size()){
        if(i == A.size()){
            while(j < B.size()){
                C.push_back(B[j]);
                ++j;
            }
        }
        else if(j == B.size()){
            while(i < A.size()){
                C.push_back(A[i]);
                ++i;
            }
        }
        else if(A[i].y <= B[j].y){
            C.push_back(A[i]);
            ++i;
        }
        else{
            C.push_back(B[j]);
            ++j;
        }
    }
    return C;
}

vector<Coordinate>
SetBufferY(vector<Coordinate> Yl, vector<Coordinate> Yr, float pivot, float delta)
{
    vector<Coordinate> Yll, Yrr;
    vector<vector<Coordinate>> Ypair;
    Ypair = Seperate(Yl, pivot - delta);
    Yll = Ypair[1];
    Ypair = Seperate(Yr, pivot + delta);
    Yrr = Ypair[0];
    return CombineSort(Yll, Yrr);
}

Pair
ClosestPoints::Combine(vector<Coordinate> Yl, vector<Coordinate> Yr, float pivot, Pair p)
{
    vector<Coordinate> Yt;
    Pair q = p;
    Yt = SetBufferY(Yl, Yr, pivot, p.distance);
    if(Yt.size() >= 9){
        for(int i = 0; i < Yt.size()-8; ++i){
            for(int j = 0; j < 7; ++j){
                if(Distance(Yt[i], Yt[i + j + 1]) <= q.distance){
                    q.distance = Distance(Yt[i], Yt[i + j + 1]);
                    q.A = Yt[i];
                    q.B = Yt[i + j + 1];
                }
            }
        }
    }
    else{
        for(int i = 0; i < Yt.size()-1; ++i){
            for(int j = i+1; j < Yt.size(); ++j){
                if(Distance(Yt[i], Yt[j]) <= q.distance){
                    q.distance = Distance(Yt[i], Yt[j]);
                    q.A = Yt[i];
                    q.B = Yt[j];
                }
            }
        }
    }
    
    return q;
}

void
ClosestPoints::Divide()
{
    closest = Divide_Sub(XSort, YSort); 
}

void
ClosestPoints::PrintClosest()
{
    cout << "Point " << closest.A.index << " and Point " << closest.B.index << " are closest pair, the distance is " << closest.distance << endl;
}

void
ClosestPoints::Bruteforce()
{
    Pair p;
    float tmp;
    p.A = Coordinates[0];
    p.B = Coordinates[1];
    p.distance = Distance(Coordinates[0], Coordinates[1]);
    for(int i = 0; i < Coordinates.size(); ++i){
        for(int j = i + 1; j < Coordinates.size(); ++j){
            tmp = Distance(Coordinates[i], Coordinates[j]);
            if(tmp < p.distance){
                p.A = Coordinates[i];
                p.B = Coordinates[j];
                p.distance = tmp;
            }
        }
    }
    cout << "Point " << p.A.index << " and Point " << p.B.index << " are closest pair, the distance is " << p.distance << endl;
}
