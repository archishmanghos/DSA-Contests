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
	vector<int> adj[N + 2];
	int degree[N + 2] = {0};
	for (int i = 1; i <= M; i++) {
		int U, V; cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
		degree[U] += 1;
		degree[V] += 1;
	}

	int start = -1, parent = -1;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 1) {
			start = i;
			break;
		}
	}

	if (start == -1) {
		cout << "No";
		return 0;
	}

	int visited[N + 2] = {0};
	while (1) {
		bool flag = true;
		visited[start] = 1;
		int node = start, par = parent;
		for (int child : adj[node]) {
			if (child != par) {
				if (flag and !visited[child]) {
					parent = start;
					start = child;
				}
				else {
					cout << "No";
					return 0;
				}
				flag = false;
			}
		}

		if (flag) break;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}