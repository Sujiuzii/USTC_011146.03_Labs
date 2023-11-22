#ifndef INTERVAL_H
#define INTERVAL_H
#include<vector>
#include<string>

using namespace std;

enum Color{
    red,
    black,
};

typedef struct Interval
{
    int low;
    int high;
}*Intervalptr;

struct RBTnode
{
    int max;
    Intervalptr interval;
    Color color;
    RBTnode* left;
    RBTnode* right;
    RBTnode* parent;
};

typedef RBTnode* RBTnodelist;

typedef struct RBTree
{
    RBTnodelist root;
    RBTnodelist NIL;
}*RBTreeptr;

// IntervalTree.cpp
void RBTinit(RBTreeptr T);
void LeftRotate(RBTreeptr T, RBTnodelist x);
void RightRotate(RBTreeptr T, RBTnodelist x);
void Insert(RBTreeptr T, RBTnodelist z);
void InsertFixup(RBTreeptr T, RBTnodelist z);
void IntervalSearch(RBTreeptr T, RBTnodelist y, Intervalptr i);

// rw.cpp
void ReadNodes(string filename, vector<vector<int>> &a);

#endif