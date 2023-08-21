#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximizeTheProfit(int n, vector<vector<int>>& offers) {
		vector<vector<pair<int, int>>> adj(n);
		for (auto i : offers) {
			adj[i[0]].push_back({i[1], i[2]});
		}

		vector<int> cache(n, -1);
		function<int(int)> dp = [&](int idx) {
			if (idx == n) return 0;
			if (cache[idx] != -1) return cache[idx];

			int answer = dp(idx + 1);
			for (auto i : adj[idx]) {
				answer = max(answer, dp(i.first + 1) + i.second);
			}

			return cache[idx] = answer;
		};

		return dp(0);
	}
};