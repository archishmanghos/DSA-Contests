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
	vector<vector<int>> A(M + 2);
	for (int i = 0; i < M; i++) {
		int C; cin >> C;
		vector<int> t;
		for (int j = 1; j <= C; j++) {
			int X; cin >> X;
			t.push_back(X);
		}
		A[i] = t;
	}

	int answer = 0;
	for (int i = 0; i < (1 << M); i++) {
		vector<int> count(N + 2, 0);
		for (int j = 0; j < M; j++) {
			if ((i >> j) & 1) {
				for (int k = 0; k < A[j].size(); k++) {
					count[A[j][k]] += 1;
				}
			}
		}

		bool ok = true;
		for (int j = 1; j <= N; j++) ok &= count[j] > 0;
		if (ok) answer += 1;
	}

	cout << answer;
	return 0;
}