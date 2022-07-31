#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {

	int N, M; cin >> N >> M;
	vector<set<int>> adj(N + 1);

	for (int i = 1; i <= M; i++) {
		int U, V; cin >> U >> V;
		adj[U].insert(V);
		adj[V].insert(U);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j : adj[i]) {
			if (j > i) {
				for (int k : adj[j]) {
					if (k > j) {
						if (adj[k].find(i) != adj[k].end()) {
							ans += 1;
						}
					}
				}
			}
		}
	}

	cout << ans;

	return 0;
}