#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	vector<int> adj[N];
	int degree[N] = {0};
	for (int i = 1; i <= M; i++) {
		int U, V; cin >> U >> V; U--, V--;
		++degree[U];
		++degree[V];
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (degree[i] == 1) {
			--degree[i];
			q.push(i);
		}
	}

	int a = -1, b = -1, c = -1;
	while (1) {
		if (b != -1) {
			a = q.size();
			break;
		}

		if (c == -1) c = q.size();
		else b = q.size();

		int sz = q.size();
		for (int i = 1; i <= sz; i++) {
			int node = q.front(); q.pop();
			for (int child : adj[node]) {
				--degree[child];
				if (degree[child] == 1) {
					--degree[child];
					q.push(child);
				}
			}
		}
	}

	cout << (b / a) << ' ' << (c / b) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}