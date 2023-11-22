#include "lcs.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    cout << "Input the first string: ";
    cin >> str1;
    cout << "Input the second string: ";
    cin >> str2;

    LCS lcs(str1, str2);
    string result = lcs.solve();
    cout << "Solution 1: " << endl;
    cout << "The longest common subsequence is: " << result << endl << "Length: " << result.size() << endl;

    result = lcs.solve2();
    cout << "Solution 2: " << endl;
    cout << "The longest common subsequence is: " << result << endl << "Length: " << result.size() << endl;

    result = lcs.solve3();
    cout << "Solution 3: " << endl;
    cout << "The longest common subsequence is: " << result << endl << "Length: " << result.size() << endl;

    return 0;
}
