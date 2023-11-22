#include"RBTInsert.h"
#include<bits/stdc++.h>

using namespace std;

int
main()
{
    RBTreeptr T = new RBTree;
    RBTinit(T);
    vector<int> Arr = ReadNodes("../insert.txt");
    for(int i = 0; i < Arr.size(); ++i){
        RBTnodelist tmp = new RBTnode;
        tmp->key = Arr[i];
        Insert(T, tmp);
    }
    cout << endl;
    cout << "NLR:\n";
    NLR(T);
    cout << "LNR:\n";
    LNR(T);
    cout << "LOT:\n";
    LOT(T);
    return 0;
}