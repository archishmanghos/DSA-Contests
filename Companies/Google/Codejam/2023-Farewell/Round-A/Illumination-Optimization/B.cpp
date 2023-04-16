#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int M, R, N; cin >> M >> R >> N;
	int X[N];
	for (int i = 0; i < N; i++) cin >> X[i];

	int end = 0;
	for (int i = 0; i < N; i++) {
		if (X[i] - R > end) {
			cout << "IMPOSSIBLE" << '\n';
			return;
		}

		end = X[i] + R;
	}

	if (end < M) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}


	int firstBulb = -1;
	for (int i = 0; i < N; i++) {
		if (X[i] - R <= 0) firstBulb = i;
		else break;
	}

	int lastBulb = -1;
	for (int i = N - 1; i >= 0; i--) {
		if (X[i] + R >= M) lastBulb = i;
		else break;
	}

	int answer = 1;
	end = X[firstBulb] + R;
	for (int i = firstBulb + 1; i <= lastBulb; i++) {
		if (i + 1 <= lastBulb) {
			if (X[i + 1] - R <= end) continue;
			answer++;
			end = X[i] + R;
		} else {
			if (end >= M) continue;
			answer++;
		}
	}

	cout << answer << '\n';
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