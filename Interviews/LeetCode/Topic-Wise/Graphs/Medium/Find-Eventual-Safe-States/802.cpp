#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool cycle (int node, vector<bool> &vis, vector<bool> &dfsVis, vector<vector<int>> &adj) {
		if (vis[node]) return dfsVis[node];
		vis[node] = dfsVis[node] = true;
		for (int child : adj[node]) {
			if (cycle (child, vis, dfsVis, adj)) return true;
		}

		dfsVis[node] = false;
		return false;
	}
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<bool> visited (n, false), dfsVisited (n, false);
		vector<int> answer;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) bool temp = cycle (i, visited, dfsVisited, graph);
			if (dfsVisited[i]) continue;
			answer.push_back(i);
		}

		return answer;
	}
};