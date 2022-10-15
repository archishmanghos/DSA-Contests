#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int M, N, P; cin >> M >> N >> P;
	vector<vector<int>> A(M + 2, vector<int>(N + 2));
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	long ans = 0;
	for (int i = 1; i <= N; i++) {
		int minSteps = 0;
		for (int j = 1; j <= M; j++) {
			if (j != P) {
				minSteps = max(minSteps, max((int)0, A[j][i] - A[P][i]));
			}
		}
		ans += minSteps;
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}