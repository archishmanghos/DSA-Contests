#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp (int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &cache) {
        if (idx1 < 0 or idx2 < 0) {
            return 0;
        }

        int &ans = cache[idx1][idx2];
        if (ans != -1) {
            return ans;
        }

        ans = max (dp (idx1 - 1, idx2, text1, text2, cache), dp (idx1, idx2 - 1, text1, text2, cache));
        if (text1[idx1] == text2[idx2]) {
            ans = max (ans, dp (idx1 - 1, idx2 - 1, text1, text2, cache) + 1);
        }

        return ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> cache (n1, vector<int> (n2, -1));
        return dp (n1 - 1, n2 - 1, text1, text2, cache);
    }
};