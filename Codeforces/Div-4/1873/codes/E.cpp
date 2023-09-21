#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int n, x; cin >> n >> x;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int low = 1, high = 1e10, answer = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		auto f = [&]() {
			int waterUsed = 0;
			for (int i = 0; i < n; i++) {
				waterUsed += max(0ll, mid - a[i]);
			}

			return waterUsed <= x;
		};

		if (f()) {
			answer = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
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