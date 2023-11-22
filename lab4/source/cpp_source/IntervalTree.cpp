#include "IntervalTree.h"
#include <bits/stdc++.h>

using namespace std;

void RBTinit(RBTreeptr T)
{
    T->NIL = new RBTnode;
    T->NIL->color = black;
    T->NIL->interval = new Interval;
    T->root = T->NIL;
    T->root->parent = T->NIL;
}

void LeftRotate(RBTreeptr T, RBTnodelist x)
{
    RBTnodelist y = new RBTnode;
    y = x->right;
    x->right = y->left;
    if (y->left != T->NIL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == T->NIL)
        T->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RightRotate(RBTreeptr T, RBTnodelist x)
{
    RBTnodelist y = new RBTnode;
    y = x->left;
    x->left = y->right;
    if (y->right != T->NIL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == T->NIL)
        T->root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void Insert(RBTreeptr T, RBTnodelist z)
{
    RBTnodelist y = T->NIL;
    RBTnodelist x = T->root;
    while (x != T->NIL)
    {
        y = x;
        if (z->interval->low < x->interval->low)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == T->NIL)
        T->root = z;
    else if (z->interval->low < y->interval->low)
        y->left = z;
    else
        y->right = z;
    z->left = T->NIL;
    z->right = T->NIL;
    z->color = red;
    InsertFixup(T, z);
    int tmp = z->max;
    while (z != T->NIL)
    {
        if (tmp >= z->max)
        {
            z->max = tmp;
            z = z->parent;
            continue;
        }
        break;
    }
    return;
}

void InsertFixup(RBTreeptr T, RBTnodelist z)
{
    RBTnodelist y;
    while (z->parent->color == red)
    {
        if (z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if (y->color == red)
            {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    LeftRotate(T, z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                RightRotate(T, z->parent->parent);
            }
        }
        else
        {
            y = z->parent->parent->left;
            if (y->color == red)
            {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    RightRotate(T, z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                LeftRotate(T, z->parent->parent);
            }
        }
    }
    T->root->color = black;
}

bool isOverlap(Intervalptr a, Intervalptr b)
{
    return (a->low <= b->high) && (b->low <= a->high);
}

void IntervalSearch(RBTreeptr T, RBTnodelist x, Intervalptr i)
{
    while (x != T->NIL)
    {
        if (isOverlap(i, x->interval))
        {
            cout << "(" << x->interval->low << ", " << x->interval->high
                 << ")" << endl;
        }
        if (x->left != T->NIL && x->left->max >= i->low)
        {
            x = x->left;
            RBTnodelist y = x->parent->right;
            if (y != T->NIL)
                IntervalSearch(T, y, i);
        }
        else
            x = x->right;
    }
}
void IntervalSearchOptimized(RBTreeptr T, RBTnodelist x, Intervalptr i, vector<Intervalptr>& overlaps)
{
    if (x == T->NIL) return;

    if (x->left != T->NIL && x->left->max >= i->low)
        IntervalSearchOptimized(T, x->left, i, overlaps);

    if (isOverlap(i, x->interval))
        overlaps.push_back(x->interval);

    if (x->right != T->NIL && x->interval->high >= i->low)
        IntervalSearchOptimized(T, x->right, i, overlaps);
}
