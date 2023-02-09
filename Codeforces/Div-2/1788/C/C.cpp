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
	if (N & 1) {
		cout << "Yes" << '\n';
		int i = 1, j = N * 2;
		for (; i <= N; i += 2, j--) {
			cout << i << ' ' << j << '\n';
		}

		i = 2;
		for (; i <= N; i += 2, j--) {
			cout << i << ' ' << j << '\n';
		}

	} else {
		cout << "No" << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}