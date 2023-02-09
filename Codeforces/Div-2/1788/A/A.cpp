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
	int A[N + 2];
	int two = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		two += A[i] == 2;
	}

	if (two & 1) cout << -1 << '\n';
	else {
		if (two == 0) {
			cout << 1 << '\n';
			return;
		}
		two >>= 1;
		for (int i = 1; i <= N; i++) {
			if (A[i] == 2) two--;
			if (two == 0) {
				cout << i << '\n';
				return;
			}
		}
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