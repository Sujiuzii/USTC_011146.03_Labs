#ifndef RBTINSERT_H
#define RBTINSERT_H

#include<vector>
#include<string>

using namespace std;

enum Color{
    red,
    black,
};

struct RBTnode
{
    int key;
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


// RBTinsert.cpp
void RBTinit(RBTreeptr T);
void LeftRotate(RBTreeptr T, RBTnodelist x);
void RightRotate(RBTreeptr T, RBTnodelist x);
void Insert(RBTreeptr T, RBTnodelist z);
void InsertFixup(RBTreeptr T, RBTnodelist z);


// rw.cpp
vector<int> ReadNodes(string filename);

// Traverse.cpp
void LNR(RBTreeptr T);
void NLR(RBTreeptr T);
void LOT(RBTreeptr T);

#endif