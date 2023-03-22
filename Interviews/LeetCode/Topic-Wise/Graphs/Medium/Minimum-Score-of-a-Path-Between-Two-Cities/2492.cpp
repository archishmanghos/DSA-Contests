#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minScore(int n, vector<vector<int>>& roads) {
		int distance[n];
		for (int i = 0; i < n; i++) distance[i] = 1e7;
		vector<vector<int>> adj[n];
		for (auto edge : roads) {
			int u = edge[0] - 1, v = edge[1] - 1, wt = edge[2];
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}

		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
		pq.push({int(1e7), 0});

		while (!pq.empty()) {
			auto it = pq.top(); pq.pop();
			int score = it[0], node = it[1];
			for (auto child : adj[node]) {
				if (distance[child[0]] > min(score, child[1])) {
					distance[child[0]] = min (score, child[1]);
					pq.push({distance[child[0]], child[0]});
				}
			}
		}

		return distance[n - 1];
	}
};