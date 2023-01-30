#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	vector<vector<int>> A(N, vector<int>(N - 1));
	vector<vector<int>> firstPos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			cin >> A[i][j];
			if (j == 0) firstPos.push_back({A[i][j], i});
		}
	}

	sort(firstPos.begin(), firstPos.end());
	vector<int> answer;
	if (firstPos[0][0] == firstPos[1][0]) {
		answer.push_back(firstPos[0][0]);
		for (int i = 0; i < N - 1; i++) {
			answer.push_back(A[firstPos[N - 1][1]][i]);
		}
	} else {
		answer.push_back(firstPos[N - 1][0]);
		for (int i = 0; i < N - 1; i++) {
			answer.push_back(A[firstPos[0][1]][i]);
		}
	}

	for (int i = 0; i < N; i++) cout << answer[i] << ' ';
	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}