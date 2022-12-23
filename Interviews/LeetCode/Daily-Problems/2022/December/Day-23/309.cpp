#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cache[5050][2];
    int dp (int day, int buy, vector<int> &prices) {
        if (day == prices.size() - 1) return (buy ? 0 : prices[day]);
        if (day == prices.size()) return 0;

        int &ans = cache[day][buy];
        if (ans != -1) return ans;

        if (buy) ans = max (dp (day + 1, 0, prices) - prices[day], dp (day + 1, 1, prices));
        else ans = max (dp (day + 2, 1, prices) + prices[day], dp (day + 1, 0, prices));
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        memset (cache, -1, sizeof(cache));
        return dp (0, 1, prices);
    }
};