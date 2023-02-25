#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int cache[n][2][2];
		memset (cache, 0, sizeof(cache));
		cache[n - 1][1][0] = prices[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			cache[i][0][0] = cache[i + 1][0][0];
			cache[i][0][1] = max (cache[i + 1][0][1], cache[i + 1][1][0] - prices[i]);
			cache[i][1][0] = max (cache[i + 1][1][0], cache[i + 1][0][0] + prices[i]);
		}

		return cache[0][0][1];
	}
};