#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> adj[N];
	for (int i = 0; i < N - 1; i++) {
		int U, V; cin >> U >> V; U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	int subtree[N];
	function<int(int, int)> dfs = [&](int node, int parent) {
		if (adj[node].size() == 1 and adj[node][0] == parent) return subtree[node] = 1;

		int sum = 0;
		for (int child : adj[node]) {
			if (child != parent) {
				sum += dfs(child, node);
			}
		}

		return subtree[node] = sum;
	};

	int sum = dfs(0, -1);
	int Q; cin >> Q;
	while (Q--) {
		int U, V; cin >> U >> V; U--, V--;
		cout << 1ll * subtree[U] * subtree[V] << '\n';
	}
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}