#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, U, V; cin >> N;
	vector<int> adj[N];
	map<pair<int, int>, int> mp;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		adj[--U].push_back(--V);
		adj[V].push_back(U);
		mp[ {U, V}] = mp[ {V, U}] = (i + 1);
	}

	vector<int> answer;
	function<int(int, int)> dfs = [&](int node, int parent) {
		int subtreeSize = 1;
		for (int child : adj[node]) {
			if (child != parent) {
				int childSize = dfs(child, node);
				if (childSize == 3) answer.push_back(mp[ {node, child}]);
				else subtreeSize += childSize;
			}
		}

		return subtreeSize;
	};

	int finalSize = dfs(0, -1);
	if (finalSize == 3) {
		cout << answer.size() << '\n';
		for (int i : answer) cout << i << ' ';
		cout << '\n';
	} else {
		cout << -1 << '\n';
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