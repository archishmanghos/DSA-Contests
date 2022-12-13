#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp (int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &cache) {
        if (r == 0) {
            return matrix[r][c];
        }

        int &ans = cache[r][c];
        if (ans != -1) {
            return ans;
        }

        ans = int(1e7);
        if (c - 1 >= 0) ans = min (ans, dp (r - 1, c - 1, matrix, cache));
        ans = min (ans, dp (r - 1, c, matrix, cache));
        if (c + 1 < (int)matrix.size()) ans = min (ans, dp (r - 1, c + 1, matrix, cache));

        ans += matrix[r][c];
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = int(1e7), n = matrix.size();
        vector<vector<int>> cache (n, vector<int> (n, -1));

        for (int i = 0; i < n; i++) {
            ans = min (ans, dp (n - 1, i, matrix, cache));
        }

        return ans;
    }
};