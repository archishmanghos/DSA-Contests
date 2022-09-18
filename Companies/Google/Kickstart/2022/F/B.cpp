#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N, Q; cin >> N >> Q;
	vector<vector<int>> adj(N);
	for (int i = 1; i <= N - 1; i++) {
		int U, V; cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	vector<int> levels, visited(N, false);
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int curNode = q.front();
			q.pop();
			visited[curNode] = true;
			if (adj[curNode].size() > 0) {
				for (int child : adj[curNode]) {
					if (!visited[child]) {
						q.push(child);
					}
				}
			}
		}
		levels.push_back(sz);
	}

	int pointer = 0, litre = 0, ans = 0;
	while (Q--) {
		int container; cin >> container;
		litre += 1;
		if (pointer < levels.size() and litre == levels[pointer]) {
			ans += levels[pointer];
			pointer += 1;
			litre = 0;
		}
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
