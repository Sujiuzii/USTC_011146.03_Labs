#include "optimalscheduling.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int
readfile(string filename, vector<int> &nums)
{
    int n, k;
    ifstream fin(filename);
    if (!fin.is_open()) {
        return -1;
    }
    fin >> n >> k;
    int num;
    for (int i = 0; i < n; i++) {
        fin >> num;
        nums.push_back(num);
    }
    fin.close();
    return k;
}
