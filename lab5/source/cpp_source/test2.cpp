#include "lcs.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    str1 = "abcdefghigkllmnopqrssstuvwxyz";
    str2 = "aabcdefghigklmnopopqrsttuvwxyz";

    LCS lcs(str1, str2);
    string result = lcs.solve2();
    cout << "Test 2: " << endl;
    cout << "The longest common subsequence is: " << result << endl << "Length: " << result.size() << endl;

    return 0;
}
