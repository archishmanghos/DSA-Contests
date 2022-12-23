#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cache[305][305];
    int dp (int l, int r, vector<int> &arr) {
        if (l > r) return 0;

        int &ans = cache[l][r];
        if (ans != -1) return ans;

        for (int i = l; i <= r; i++) {
            int leftBalloon = (l - 1 >= 0 ? arr[l - 1] : 1);
            int rightBalloon = (r + 1 < arr.size() ? arr[r + 1] : 1);
            int points = leftBalloon * arr[i] * rightBalloon;
            ans = max (ans, dp (l, i - 1, arr) + dp (i + 1, r, arr) + points);
        }

        return ans;
    }
    int maxCoins(int N, vector<int> &arr) {
        memset (cache, -1, sizeof (cache));
        return dp (0, N - 1, arr);
    }
};