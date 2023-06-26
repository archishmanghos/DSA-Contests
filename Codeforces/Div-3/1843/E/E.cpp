#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	int segments[M][2];
	for (int i = 0; i < M; i++) {
		cin >> segments[i][0] >> segments[i][1];
		--segments[i][0], --segments[i][1];
	}

	int Q; cin >> Q;
	int queries[Q];
	for (int i = 0; i < Q; i++) {
		cin >> queries[i];
		--queries[i];
	}

	int answer = -1, low = 0, high = Q - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		function<bool(void)> f = [&]() {
			int arr[N + 1] = {0}, pref[N + 1];
			for (int i = 0; i <= mid; i++) ++arr[queries[i]];
			pref[0] = arr[0];
			for (int i = 1; i < N; i++) pref[i] = pref[i - 1] + arr[i];

			for (int i = 0; i < M; i++) {
				int l = segments[i][0], r = segments[i][1];
				int span = r - l + 1, sum = pref[r] - (l - 1 >= 0 ? pref[l - 1] : 0);
				if (sum > span / 2) return true;
			}

			return false;
		};

		if (f()) {
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