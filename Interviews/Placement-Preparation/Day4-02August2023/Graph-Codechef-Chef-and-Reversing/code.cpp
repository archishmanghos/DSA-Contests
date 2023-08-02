#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	map<pair<int, int>, int> mp;
	vector<int> adj[N + 2];
	for (int i = 1; i <= M; i++) {
		int U, V; cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
		mp[ {U, V}] = 1;
	}

	vector<int> dist(N + 2, M + 5);
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0, 1});
	dist[1] = 0;

	while (!pq.empty()) {
		auto it = pq.top(); pq.pop();
		int edgesReversed = it[0], node = it[1];

		for (int child : adj[node]) {
			if (mp.find({node, child}) != mp.end()) {
				if (dist[child] > edgesReversed) {
					dist[child] = edgesReversed;
					pq.push({edgesReversed, child});
				}
			} else {
				if (dist[child] > edgesReversed + 1) {
					dist[child] = edgesReversed + 1;
					pq.push({edgesReversed + 1, child});
				}
			}
		}
	}

	cout << (dist[N] <= M ? dist[N] : -1);
	return 0;
}