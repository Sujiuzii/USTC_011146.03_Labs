#include "optimalscheduling.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int
main()
{
    Timer timer;
    vector<int> time;
    int k = readfile("tests/test1.txt", time);
    Optimal optimal1(time, time.size(), k);
    cout << "Test 1: " << endl;
    timer.reset();
    optimal1.optimalscheduling();
    for (int i = 0; i < optimal1.bestmatch.size(); i++) {
        cout << "Task " << i + 1 << "\t-> Machine " << optimal1.bestmatch[i] + 1 << endl;
    }
    cout << "Cost: " << optimal1.cost << endl; 
    cout << "Time: " << timer.elapsed() << "us" << endl;
    
    time.clear();
    k = readfile("tests/test2.txt", time);
    Optimal optimal2(time, time.size(), k);
    cout << "Test 2: " << endl;
    timer.reset();
    optimal2.optimalscheduling();
    for (int i = 0; i < optimal2.bestmatch.size(); i++) {
        cout << "Task " << i + 1 << "\t-> Machine " << optimal2.bestmatch[i] + 1 << endl;
    }
    cout << "Cost: " << optimal2.cost << endl; 
    cout << "Time: " << timer.elapsed() << "us" << endl;

    time.clear();
    k = readfile("tests/test3.txt", time);
    Optimal optimal3(time, time.size(), k);
    cout << "Test 3: " << endl;
    timer.reset();
    optimal3.optimalscheduling();
    for (int i = 0; i < optimal3.bestmatch.size(); i++) {
        cout << "Task " << i + 1 << "\t-> Machine " << optimal3.bestmatch[i] + 1 << endl;
    }
    cout << "Cost: " << optimal3.cost << endl; 
    cout << "Time: " << timer.elapsed() << "us" << endl;

    return 0;
}
