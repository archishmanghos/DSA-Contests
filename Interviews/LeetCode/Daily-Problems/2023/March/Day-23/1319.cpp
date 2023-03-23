#include <bits/stdc++.h>
using namespace std;

class Solution {
	int vis[100100];
	vector<int> adj[100100];
public:
	void dfs (int node) {
		if (vis[node]) return;
		vis[node] = 1;
		for (int child : adj[node]) dfs(child);
	}
	int makeConnected(int n, vector<vector<int>>& connections) {
		int m = connections.size();
		if (m < n - 1) return -1;
		for (auto edge : connections) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}

		int components = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs (i);
				components++;
			}
		}

		return (components - 1);
	}
};