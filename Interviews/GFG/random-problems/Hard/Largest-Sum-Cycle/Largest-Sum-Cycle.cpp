#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long largestSumCycle(int N, vector<int> Edge) {
		vector<bool> visited (100100, false);
		vector<int> st, adj[100100];

		auto topoSort = [&](int node, auto && topoSort) {
			if (visited[node]) return;
			visited[node] = true;
			if (Edge[node] != -1) topoSort (Edge[node], topoSort);
			st.push_back(node);
		};

		auto dfs = [&](int node, long long & cs, auto && dfs) {
			if (visited[node]) return;
			cs += node;
			visited[node] = true;
			for (int child : adj[node]) dfs (child, cs, dfs);
		};

		for (int i = 0; i < N; i++) {
			if (!visited[i]) topoSort (i, topoSort);
		}

		for (int i = 0; i < N; i++) {
			if (Edge[i] != -1) adj[Edge[i]].push_back(i);
		}

		visited.assign (N, false);
		long long answer = -1;
		while (st.size()) {
			int curNode = st.back();
			st.pop_back();
			if (visited[curNode]) continue;

			long long cycleSum = 0;
			dfs (curNode, cycleSum, dfs);

			if (cycleSum == curNode) continue;
			answer = max (answer, cycleSum);
		}

		return answer;
	}
};