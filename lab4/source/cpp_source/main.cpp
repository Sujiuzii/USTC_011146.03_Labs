#include"IntervalTree.h"
#include<bits/stdc++.h>

using namespace std;

int
main()
{
    RBTreeptr T = new RBTree;
    RBTinit(T);
    vector<vector<int>> Arr;
    ReadNodes("../insert.txt", Arr);
    for(int i = 0; i < Arr.size(); ++i){
        RBTnodelist tmp = new RBTnode;
        Intervalptr itmp = new Interval;
        itmp->low = Arr[i][0];
        itmp->high = Arr[i][1];
        tmp->interval = itmp;
        tmp->max = Arr[i][1];
        tmp->color = red;
        tmp->left = tmp->right = tmp->parent = nullptr;
        Insert(T, tmp);
    }
    cout << "Input the interval(low): ";
    Intervalptr y;
    cin >> y->low;
    cout << "Input the interval(high): ";
    cin >> y->high;
    
    cout << "\nOverlapped interval(s): \n";
    IntervalSearch(T, T->root, y);
    
    return 0;
}