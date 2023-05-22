#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	set<int> adj[N];
	vector<int> adj2[N];
	int indegree[N];
	memset(indegree, 0, sizeof(indegree));
	for (int i = 0; i < N; i++) {
		int X; cin >> X; X--;
		if (adj[X].find(i) == adj[X].end()) {
			adj[i].insert(X);
			++indegree[X];
		}
		adj2[i].push_back(X);
		adj2[X].push_back(i);
	}

	int visited[N], pathVisited[N];
	memset(visited, 0, sizeof(visited));
	memset(pathVisited, 0, sizeof(pathVisited));

	function<bool(int)> isCycle = [&](int node) {
		if (visited[node]) {
			if (pathVisited[node]) return true;
			return false;
		}

		visited[node] = pathVisited[node] = 1;
		for (int child : adj[node]) {
			if (isCycle(child)) return true;
		}

		pathVisited[node] = 0;
		return false;
	};

	function<void(int)> dfs = [&](int node) {
		if (visited[node]) return;

		visited[node] = 1;
		for (int child : adj2[node]) dfs(child);
	};

	int minimum = 0, normal = 0, maximum = 0;
	for (int i = 0; i < N; i++) {
		if (!indegree[i] and !visited[i]) {
			if (isCycle(i)) ++minimum;
			else ++normal;
		}
	}

	for (int i = 0; i < N; i++) {
		if (indegree[i] == 1 and !visited[i]) {
			if (isCycle(i)) ++minimum;
			else ++normal;
		}
	}

	minimum += (normal > 0);

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i);
			++maximum;
		}
	}

	cout << minimum << ' ' << maximum << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}