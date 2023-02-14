#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minCost(vector<vector<int>> &colors, int N) {
		vector<vector<int>> cache (N, vector<int> (3, 0));
		for (int i = 0; i < 3; i++) cache[0][i] = colors[0][i];
		for (int i = 1; i < N; i++) {
			cache[i][0] = min (cache[i - 1][1], cache[i - 1][2]) + colors[i][0];
			cache[i][1] = min (cache[i - 1][0], cache[i - 1][2]) + colors[i][1];
			cache[i][2] = min (cache[i - 1][0], cache[i - 1][1]) + colors[i][2];
		}

		return *min_element(cache[N - 1].begin(), cache[N - 1].end());
	}
};