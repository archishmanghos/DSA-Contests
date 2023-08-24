#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size(), colour[n];
		memset(colour, -1, sizeof(colour));

		function<bool(int)> dfs = [&](int node) {
			for (int child : graph[node]) {
				if (colour[child] == -1) {
					colour[child] = 1 - colour[node];
					if (!dfs(child)) return false;
				} else {
					if (colour[child] == colour[node]) return false;
				}
			}

			return true;
		};

		for (int i = 0; i < n; i++) {
			if (colour[i] == -1) {
				colour[i] = 1;
				if (!dfs(i)) return false;
			}
		}

		return true;
	}
};
