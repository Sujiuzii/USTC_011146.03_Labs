#include"RBTInsert.h"
#include<bits/stdc++.h>
#include<cstdlib>
#include<fstream>

using namespace std;

void
NLR_sub(RBTreeptr T, RBTnodelist x)
{
    if(!T || x == T->NIL) return;
    ofstream fout;
    fout.open("../NLR.txt", ios_base::app);
    fout << x->key << ", ";
    cout << x->key << ", ";
    if(x->color){
        fout << "black" << endl;
        cout << "black" << endl;
    } 
    else{
        fout << "red" << endl;
        cout << "red" << endl;
    }
    fout.close();
    NLR_sub(T, x->left);
    NLR_sub(T, x->right);
}

void
NLR(RBTreeptr T)
{
    ofstream fout;
    fout.open("../NLR.txt", ios_base::trunc);
    fout.close();
    NLR_sub(T, T->root);
}

void
LNR_sub(RBTreeptr T, RBTnodelist x)
{
    if(!T || x == T->NIL) return;
    LNR_sub(T, x->left);
    ofstream fout;
    fout.open("../LNR.txt", ios_base::app);
    fout << x->key << ", ";
    cout << x->key << ", ";
    if(x->color){
        fout << "black" << endl;
        cout << "black" << endl;
    } 
    else{
        fout << "red" << endl;
        cout << "red" << endl;
    }
    fout.close();
    LNR_sub(T, x->right);
}

void
LNR(RBTreeptr T)
{
    ofstream fout;
    fout.open("../LNR.txt", ios_base::trunc);
    fout.close();
    LNR_sub(T, T->root);
}

void
LOT(RBTreeptr T)
{
    queue<RBTnodelist> Q;
    ofstream fout;
    fout.open("../LOT.txt", ios_base::trunc);
    Q.push(T->root);
    // int depth = 0;
    while (!Q.empty())
    {
        RBTnodelist y = Q.front();
        Q.pop();
        fout << y->key << ", ";
        cout << y->key << ", ";
        if(y->color){
            fout << "black" << endl;
            cout << "black" << endl;
        }
        else{
            fout << "red" << endl;
            cout << "red" << endl;
        }
        if(y->left != T->NIL)
            Q.push(y->left);
        if(y->right != T->NIL)
            Q.push(y->right);
    }
    fout.close();
}
