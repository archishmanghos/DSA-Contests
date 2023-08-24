<h2>1203. Sort Items by Groups Respecting Dependencies </h2>

[Link to Problem](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/)

```c++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
		vector<int> degree(n, 0);
		vector<vector<int>> adj(n);
		for (int i = 0; i < beforeItems.size(); i++) {
			for (int j : beforeItems[i]) {
				degree[i]++;
				adj[j].push_back(i);
			}
		}
		for (int i = 0; i < n; i++) {
			if (group[i] == -1) group[i] = m++;
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (degree[i] == 0) q.push(i);
		}

		vector<int> toposort;
		while (!q.empty()) {
			int node = q.front(); q.pop();
			toposort.push_back(node);

			for (int child : adj[node]) {
				degree[child]--;
				if (degree[child] == 0) q.push(child);
			}
		}

		if (toposort.size() < n) return {};

		vector<int> group_degree(m, 0);
		vector<int> group_toposort;
		vector<vector<int>> group_adj(m);
		for (int i = 0; i < beforeItems.size(); i++) {
			for (int j : beforeItems[i]) {
				if (group[i] != group[j]) {
					group_degree[group[i]]++;
					group_adj[group[j]].push_back(group[i]);
				}
			}
		}

		for (int i = 0; i < m; i++) {
			if (group_degree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int node = q.front(); q.pop();
			group_toposort.push_back(node);

			for (int child : group_adj[node]) {
				group_degree[child]--;
				if (group_degree[child] == 0) q.push(child);
			}
		}

		if (group_toposort.size() < m) return {};

		vector<vector<int>> groups(m);
		for (int i = 0; i < n; i++) {
			groups[group[toposort[i]]].push_back(toposort[i]);
		}

		vector<int> answer;
		for (int gr : group_toposort) {
			for (int j : groups[gr]) answer.push_back(j);
		}

		return answer;
	}
};

```