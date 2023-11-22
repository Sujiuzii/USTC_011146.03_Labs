#ifndef LCS_H
#define LCS_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum Direction { UP, LEFT, DIAG };

class LCS {
public:
    LCS(const string& s1, const string& s2) : s1_(s1), s2_(s2) {}

    string solve();
    string solve2();
    string solve2sub(const string& s1, const string& s2);
    string solve3();
    string solve3sub(const string& s1, const string& s2);

private:
    string s1_, s2_;
};

#endif // LCS_H
