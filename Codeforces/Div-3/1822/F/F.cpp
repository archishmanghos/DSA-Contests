#include <bits/stdc++.h>
#define int long long
using namespace std;

const int LOG = 20;
int N, K, C, U, V;
vector<int> adj[200200];
int depth[200200], up[200200][20];

void dfs(int node, int parent, int d, vector<int> &leafNodes) {
	up[node][0] = parent;
	for (int i = 1; i < LOG; i++) {
		if (up[node][i - 1] != -1) up[node][i] = up[up[node][i - 1]][i - 1];
		else up[node][i] = -1;
	}

	depth[node] = d;
	if (adj[node].size() == 1) leafNodes.push_back(node);
	for (int child : adj[node]) {
		if (child != parent) {
			dfs(child, node, d + 1, leafNodes);
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	int k = depth[b] - depth[a];
	for (int i = LOG - 1; i >= 0; i--) {
		if (k & (1 << i)) {
			b = up[b][i];
		}
	}

	if (a == b) return a;

	for (int i = LOG - 1; i >= 0; i--) {
		if (up[a][i] != up[b][i]) {
			a = up[a][i], b = up[b][i];
		}
	}

	return up[a][0];
}

void solve() {
	cin >> N >> K >> C;

	for (int i = 1; i <= N; i++) adj[i].clear();
	for (int i = 1; i <= N; i++) memset(up[i], 0, sizeof(up[i]));
	memset(depth, 0, (N + 5) * sizeof(int));

	for (int i = 1; i <= N - 1; i++) {
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	vector<int> leafNodes;
	dfs(1, -1, 0, leafNodes);

	int a = 0, dist = -1;
	for (int leaf : leafNodes) {
		if (dist < depth[leaf]) {
			dist = depth[leaf];
			a = leaf;
		}
	}

	int answer = dist * K;
	int b, diameter = -1;
	for (int leaf : leafNodes) {
		if (leaf == a) continue;
		int lca = LCA(leaf, a);
		int distance = depth[a] + depth[leaf] - 2 * depth[lca];
		if (diameter < distance) {
			diameter = distance;
			b = leaf;
		}
	}

	for (int leaf : leafNodes) {
		int lca_a = LCA(leaf, a), lca_b = LCA(leaf, b);
		int dist_a = depth[a] + depth[leaf] - 2 * depth[lca_a];
		int dist_b = depth[b] + depth[leaf] - 2 * depth[lca_b];

		if (dist_a > dist_b) {
			answer = max(answer, dist_a * K - depth[leaf] * C);
		} else {
			answer = max(answer, dist_b * K - depth[leaf] * C);
		}
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}