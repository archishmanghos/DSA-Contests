#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int N;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	cin >> N;
	vector<vector<char>> A(N + 2, vector<char>(N + 2));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == '-') continue;
			if (A[i][j] == 'W' and A[j][i] != 'L') {
				cout << "incorrect";
				return 0;
			}
			if (A[i][j] == 'L' and A[j][i] != 'W') {
				cout << "incorrect";
				return 0;
			}
			if (A[i][j] == 'D' and A[j][i] != 'D') {
				cout << "incorrect";
				return 0;
			}
		}
	}

	cout << "correct";

	return 0;
}