#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cache[505][505];
    int dp (int idx, int dishes, vector<int> &satisfaction) {
        if (idx == satisfaction.size() - 1) return satisfaction.back() > 0 ? satisfaction.back() * dishes : 0;

        int &ans = cache[idx][dishes];
        if (ans != -1) return ans;

        ans = max (dp (idx + 1, dishes, satisfaction), dp (idx + 1, dishes + 1, satisfaction) + satisfaction[idx] * dishes);
        return ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort (satisfaction.begin(), satisfaction.end());
        memset(cache, -1, sizeof(cache));
        return dp (0, 1, satisfaction);
    }
};