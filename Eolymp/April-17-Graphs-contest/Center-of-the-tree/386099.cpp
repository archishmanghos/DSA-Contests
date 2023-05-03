#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[200200];
int parent[200200], degree[200200];

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	parent[1] = -1;
	for (int i = 2; i <= N; i++) {
		cin >> parent[i];
		degree[i]++;
		degree[parent[i]]++;
		adj[i].push_back(parent[i]);
		adj[parent[i]].push_back(i);
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 1) {
			q.push(i);
			degree[i]--;
		}
	}

	vector<vector<int>> answer;
	while (!q.empty()) {
		int sz = q.size();
		vector<int> temp;
		for (int i = 1; i <= sz; i++) {
			int node = q.front(); q.pop();
			temp.push_back(node);
			for (int child : adj[node]) {
				degree[child]--;
				if (degree[child] == 1) {
					q.push(child);
					degree[child]--;
				}
			}
		}
		answer.push_back(temp);
	}

	sort(answer.back().begin(), answer.back().end());
	for (int i : answer.back()) cout << i << ' ';
	return 0;
}