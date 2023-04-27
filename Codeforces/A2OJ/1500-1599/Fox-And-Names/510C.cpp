#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int indegree[26] = {0};
	string A[N];
	vector<int> adj[26];
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 0; i + 1 < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int sz = min(A[i].size(), A[j].size());
			int idx = -1;
			for (int k = 0; k < sz; k++) {
				if (A[i][k] != A[j][k]) {
					idx = k;
					break;
				}
			}

			if (idx == -1) {
				if (A[i].size() > A[j].size()) {
					cout << "Impossible";
					return 0;
				}
				continue;
			}
			char u = A[i][idx], v = A[j][idx];
			indegree[v - 'a']++;
			adj[u - 'a'].push_back(v - 'a');
		}
	}

	vector<char> answer;
	for (int i = 0; i < 26; i++) {
		if (indegree[i] == 0) {
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int node = q.front(); q.pop();
				indegree[node]--;
				answer.push_back((char)(node + 'a'));

				for (int child : adj[node]) {
					indegree[child]--;
					if (indegree[child] == 0) q.push(child);
				}
			}
		}
	}

	if (answer.size() < 26) cout << "Impossible";
	else {
		for (char c : answer) cout << c;
	}
	return 0;
}