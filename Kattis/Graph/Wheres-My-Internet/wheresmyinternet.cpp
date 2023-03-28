#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[200200];
int visited[200200];

void dfs(int node) {
	if (visited[node]) return;
	visited[node] = 1;
	for (int child : adj[node]) {
		dfs(child);
	}
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	memset(visited, 0, N * sizeof(int));

	dfs(0);
	bool answer = false;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			answer = true;
			cout << (i + 1) << '\n';
		}
	}

	if (!answer) {
		cout << "Connected" << '\n';
	}
	return 0;
}