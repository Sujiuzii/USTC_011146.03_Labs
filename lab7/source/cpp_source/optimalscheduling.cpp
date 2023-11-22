#include "optimalscheduling.h"
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

void
Optimal::optimalscheduling()
{
    optimalschedulingsub(0);
}

void
Optimal::optimalschedulingsub(int i)
{   
    int flag;
    int tmp = *max_element(current.begin(), current.end());
    if (cost <= tmp)
        return;
    if (i == n) {   
        // the following code will lower the performance quite a lot
        // if(tmp <= cost){
        //     cost = tmp;
        //     bestmatch = match;
        // }   
        cost = tmp;
        bestmatch = match;
        return;
    }
    for (int j = 0; j < k; j++) {
        flag = 1;
        for (int l = 0; l < j; l++) {
            if (current[l] == current[j]) {
                flag = 0;
                break;
            }
        }
        if (!flag || current[j] + Time[i] >= cost)
            continue;
        current[j] += Time[i];
        match[i] = j;
        optimalschedulingsub(i + 1);
        current[j] -= Time[i];
    }
}
