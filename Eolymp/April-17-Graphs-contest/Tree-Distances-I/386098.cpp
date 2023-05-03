#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[200200];
int parent[200200], depth[200200];
int LOG = 19;
int up[200200][20];

void dfs(int node, int par, int d) {
	up[node][0] = par;
	for (int j = 1; j <= LOG; j++) {
		if (up[node][j - 1] != -1) up[node][j] = up[up[node][j - 1]][j - 1];
		else up[node][j] = -1;
	}

	depth[node] = d;
	for (int child : adj[node]) {
		if (child != par) {
			dfs(child, node, d + 1);
		}
	}
}

void dfs(int node, int par, int depth, vector<int> &answer) {
	if (answer[0] < depth) answer = {depth, node};
	for (int child : adj[node]) {
		if (child != par) {
			dfs(child, node, depth + 1, answer);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int k = depth[a] - depth[b];

	for (int i = LOG; i >= 0; i--) {
		if (k & (1 << i)) {
			a = up[a][i];
		}
	}

	if (a == b) return a;
	for (int i = LOG; i >= 0; i--) {
		if (up[a][i] != up[b][i]) {
			a = up[a][i];
			b = up[b][i];
		}
	}

	return up[a][0];
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		int U, V; cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	vector<int> answer = {0, 1};
	dfs(1, -1, 0, answer);
	int a = answer[1], d1 = answer[0];
	answer = {0, a};
	dfs(a, -1, 0, answer);
	int b = answer[1], d2 = answer[0];
	dfs(1, -1, 0);

	for (int i = 1; i <= N; i++) {
		int distToA = depth[i] + depth[a] - 2 * depth[lca(i, a)];
		int distToB = depth[i] + depth[b] - 2 * depth[lca(i, b)];

		cout << max(distToA, distToB) << ' ';
	}

	return 0;
}