#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, M, U, V, A[100100];
vector<int> adj[100100], vis(100100);

void dfs(int node, int &sum) {
	if (vis[node]) return;

	vis[node] = 1;
	sum += A[node];
	for (int child : adj[node]) dfs(child, sum);
}

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) adj[i].clear();
	for (int i = 1; i <= M; i++) {
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	int totSum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		totSum += A[i];
	}

	vis.assign(N + 2, 0);
	vector<int> sums;
	int connected = 0;
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			int sum = 0;
			dfs(i, sum);
			sums.push_back(sum);
			connected += 1;
		}
	}

	vector<int> actual;
	for (int i = 0; i < connected; i++) actual.push_back(totSum / connected);
	int remSum = totSum % connected;
	int k = 0;
	while (remSum--) actual[k++] += 1;
	sort(sums.begin(), sums.end());
	reverse(sums.begin(), sums.end());

	int i = 0, j = connected - 1, answer = 0;
	while (i < j) {
		if (actual[i] == sums[i]) i++;
		if (actual[j] == sums[j]) j--;

		int x = min(sums[i] - actual[i], actual[j] - sums[j]);
		sums[i] -= x;
		sums[j] += x;
		answer += x;
	}

	cout << answer << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}