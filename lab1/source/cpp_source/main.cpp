#include"quicksort.h"
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

int
main()
{
    vector<int> test2, test;
    Timer tm = Timer();

    // for (int j = 0; j < 1000; ++j){
    //     test.push_back(j+1);
    // }

    test2 = ReadArr("../data/0.in");
    // sort(test2.begin(), test2.end());
    double Time = 0.0;
    // test2 = {5,66,9,48,63,21,48,96,11111};
    Quicksort qs = Quicksort(test2.size(), test2);


    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.RandomPivot();
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "random: " << Time/50.0 << endl;
    Time = 0.0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.GatherSort();
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "gather: " << Time/50.0 << endl;
    Time = 0.0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.MOTSort();
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "medianof3: " << Time/50.0 << endl;
    Time = 0.0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.QuickInsertSort(5);
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "insert5: " << Time/50.0 << endl;
    Time = 0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.QuickInsertSort(10);
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "insert10: " << Time/50.0 << endl;
    Time = 0.0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.QuickInsertSort(20);
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "insert20: " << Time/50.0 << endl;
    Time = 0.0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.QuickInsertSort(50);
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "insert50: " << Time/50.0 << endl;
    Time = 0.0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.SimpleQuickSort();
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "simple: " << Time/50.0 << endl;
    Time = 0.0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        sort(test2.begin(), test2.end());
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "qsort: " << Time/50.0 << endl;
    Time = 0.0;

    for(int i = 1; i < 50; ++i){
        qs = Quicksort(test2.size(), test2);
        qs.SetSeed(static_cast<unsigned>(time(nullptr)));
        tm.start();
        qs.Sort(20);
        tm.stop();
        Time += tm.elapsedMilliseconds();
    }
    cout << "Sort: " << Time/50.0 << endl;
    Time = 0.0;

    WriteArr(qs.Arr, "../sorted.txt");

    return 0;
}