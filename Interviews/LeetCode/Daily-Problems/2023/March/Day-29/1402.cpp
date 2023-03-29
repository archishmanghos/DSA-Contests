#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSatisfaction(vector<int>& satisfaction) {
		sort(satisfaction.begin(), satisfaction.end());
		int cache[505][505], n = satisfaction.size();
		memset (cache, 0, sizeof(cache));
		for (int i = 1; i <= n; i++) cache[n - 1][i] = (satisfaction[n - 1] < 0 ? 0 : i * satisfaction[n - 1]);
		for (int i = n - 2; i >= 0; i--) {
			for (int j = n - 1; j >= 1; j--) {
				cache[i][j] = max(cache[i + 1][j], cache[i + 1][j + 1] + j * satisfaction[i]);
			}
		}

		return cache[0][1];
	}
};