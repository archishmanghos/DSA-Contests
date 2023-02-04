#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
		vector<int> adj[n], indegree(n, 0);
		for (auto edge : prerequisites) {
			adj[edge[1]].push_back(edge[0]);
			indegree[edge[0]] += 1;
		}

		queue<int> q;
		vector<int> answer;
		for (int i = 0; i < n; i++) {
			if (!indegree[i]) {
				q.push(i);
				indegree[i] -= 1;
			}
		}

		while (!q.empty()) {
			int task = q.front();
			q.pop();

			answer.push_back(task);
			for (int child : adj[task]) indegree[child] -= 1;
			for (int i = 0; i < n; i++) {
				if (indegree[i] == 0) {
					q.push(i);
					indegree[i] -= 1;
				}
			}
		}

		if (answer.size() == n) return answer;
		return {};
	}
};