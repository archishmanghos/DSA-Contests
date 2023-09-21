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
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) a[i] += a[i - 1];
	}
	int h[n]; for (int i = 0; i < n; i++) cin >> h[i];

	int answer = 0, l = 0;
	for (int i = 0; i < n - 1;) {
		if (h[i] % h[i + 1] == 0) {
			int sum = a[i] - (l - 1 >= 0 ? a[l - 1] : 0);
			while (sum > x) sum -= a[l++];
			answer = max(answer, i - l + 1);
			i++;
		} else {
			int sum = a[i] - (l - 1 >= 0 ? a[l - 1] : 0);
			while (l <= i) {
				if (sum <= x) answer = max(answer, i - l + 1);
				sum -= a[l++];
			}
			i++;
			l = i;
		}
	}

	int sum = a[n - 1] - (l - 1 >= 0 ? a[l - 1] : 0);
	while (l < n) {
		if (sum <= x) answer = max(answer, n - l);
		sum -= a[l];
		l++;
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