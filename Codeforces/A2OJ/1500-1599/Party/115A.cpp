#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2020];
int maxDepth(int node, int parent) {
	int depth = 0;
	for (int i : adj[node]) {
		if (i != parent) depth = max(depth, maxDepth(i, node));
	}

	return 1 + depth;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	vector<int> roots;
	for (int i = 0; i < N; i++) {
		int P; cin >> P;
		if (P != -1) adj[P - 1].push_back(i);
		else roots.push_back(i);
	}

	int answer = 0;
	for (int node : roots) answer = max(answer, maxDepth(node, -1));

	cout << answer;
	return 0;
}