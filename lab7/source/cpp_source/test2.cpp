#include "optimalscheduling.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int
main()
{
    vector<int> time;
    Timer timer;
    int k = readfile("tests/test2.txt", time);
    Optimal optimal(time, time.size(), k);
    timer.reset();
    optimal.optimalscheduling();
    for (int i = 0; i < optimal.bestmatch.size(); i++) {
        cout << "Task " << i + 1 << "\t-> Machine " << optimal.bestmatch[i] + 1 << endl;
    }
    cout << "Cost: " << optimal.cost << endl; 
    cout << "Time: " << timer.elapsed() << "us" << endl;
}
