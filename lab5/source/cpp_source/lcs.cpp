#include"lcs.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

string
LCS::solve()
{
    // c is the length of the longest common subsequence
    // b is the direction of the longest common subsequence
    int m = s1_.size(), n = s2_.size();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    vector<vector<Direction>> b(m + 1, vector<Direction>(n + 1, UP));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1_[i - 1] == s2_[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = DIAG;
            } else {
                if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = UP;
                } else {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = LEFT;
                }
            }
        }
    }

    string ans;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (b[i][j] == DIAG) {
            ans += s1_[i - 1];
            i--, j--;
        } else if (b[i][j] == UP) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string
LCS::solve2()
{
    if(s1_.size() < s2_.size()) {
        return solve2sub(s2_, s1_);
    } else {
        return solve2sub(s1_, s2_);
    }
}

string
LCS::solve2sub(const string& s1, const string& s2)
{
    int m = s1.size(), n = s2.size();
    string ans;
    int tmp;
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int last = 0;
        tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp = c[j];
            if (s1[i - 1] == s2[j - 1]) {
                c[j] = last + 1;
            } else {
                if (c[j - 1] >= c[j]) {
                    c[j] = c[j - 1];
                }
            }
            last = tmp;
        }
    }

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1];
            while (c[j - 1] == c[j]) {
                j--;
            }
            i--, j--;
        } else {
            if (c[j - 1] < c[j]) {
                i--;
            } else {
                j--;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

string
LCS::solve3()
{
    if (s1_.size() > s2_.size()) {
        return solve3sub(s1_, s2_);
    } else {
        return solve3sub(s2_, s1_);
    }
}

string
LCS::solve3sub(const string& s1, const string& s2)
{
    int m = s1.size(), n = s2.size();
    string ans;
    int tmp;
    int nowindex = 0;
    vector<vector<int>> c(2, vector(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        nowindex = i & 1;
        tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp = c[nowindex][j];
            if (s1[i - 1] == s2[j - 1]) {
                c[nowindex][j] = c[nowindex ^ 1][j - 1] + 1;
            } else {
                if (c[nowindex ^ 1][j] >= c[nowindex][j - 1]) {
                    c[nowindex][j] = c[nowindex ^ 1][j];
                } else {
                    c[nowindex][j] = c[nowindex][j - 1];
                }
            }
        }
    }

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1];
            while (c[nowindex][j - 1] == c[nowindex][j]) {
                j--;
            }
            i--, j--;
        } else {
            if (c[nowindex][j - 1] < c[nowindex][j]) {
                i--;
            } else {
                j--;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
