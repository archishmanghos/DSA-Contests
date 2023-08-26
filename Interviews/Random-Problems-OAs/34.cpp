#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	int A[N][M];
	int totalHours = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			totalHours += A[i][j];
		}
	}

	int P; cin >> P;
	int prior_commitments[25] = {0};
	for (int i = 0; i < P; i++) {
		int X, Y; cin >> X >> Y;
		prior_commitments[X]++;
		prior_commitments[Y]--;
	}

	for (int i = 1; i < 25; i++) prior_commitments[i] += prior_commitments[i - 1];

	int K; cin >> K;
	int low = 0, high = 23, answer = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		auto check = [&]() {
			int count_time_slots = 0;
			for (int i = 0; i <= mid; i++) {
				count_time_slots += prior_commitments[i] == 0;
			}
			return (K * count_time_slots) >= totalHours;
		};

		if (check()) {
			answer = mid + 1;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}