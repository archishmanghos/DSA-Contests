#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	int A[M + 2], goTo[N + 2];
	memset(goTo, -1, sizeof(goTo));

	for (int i = 1; i <= M; i++) {
		cin >> A[i];
		goTo[A[i]] = A[i] + 1;
	}

	int visited[N + 2];
	memset(visited, 0, sizeof(visited));

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			int node = i;
			vector<int> v;
			while (node != -1) {
				v.push_back(node);
				visited[node] = 1;
				node = goTo[node];
			}

			sort(v.begin(), v.end(), greater<int>());
			for (int x : v) cout << x << ' ';
		}
	}

	cout << '\n';
	return 0;
}