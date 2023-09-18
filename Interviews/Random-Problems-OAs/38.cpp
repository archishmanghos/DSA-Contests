#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int solution(int N, vector<int> &A,  vector<int> &B) {
	vector<int> adj[N];
	int degree[N] = {0};
	for (int i = 0; i < A.size(); i++) {
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
		degree[A[i]]++;
		degree[B[i]]++;
	}

	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (degree[i] <= 1) {
			q.push(i);
			degree[i]--;
		}
	}

	int answer = 0;
	while (!q.empty()) {
		int sz = q.size();
		answer++;
		for (int i = 1; i <= sz; i++) {
			int node = q.front(); q.pop();
			for (int child : adj[node]) {
				degree[child]--;
				if (degree[child] == 0 or degree[child] == 1) {
					q.push(child);
					degree[child]--;
				}
			}
		}
	}

	return answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) cin >> A[i] >> B[i];
	cout << solution(N, A, B);
	return 0;
}