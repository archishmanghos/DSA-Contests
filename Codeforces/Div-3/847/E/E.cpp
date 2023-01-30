#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int XOR; cin >> XOR;
	int sum = (XOR << 1ll), A = (sum - XOR) >> 1ll;
	int a = 0, b = 0;

	for (int i = 0; i < 30; i++) {
		if (!((XOR >> i) & 1) and !((A >> i) & 1)) continue;
		else if (!((XOR >> i) & 1) and ((A >> i) & 1)) {
			a = ((1ll << i) | a);
			b = ((1ll << i) | b);
		} else if (((XOR >> i) & 1) and !((A >> i) & 1)) {
			a = ((1 << i) | a);
		} else {
			cout << -1 << '\n';
			return;
		}
	}

	int s2 = (a + b) >> 1ll;
	if (s2 == XOR) {
		cout << a << ' ' << b << '\n';
		return;
	}

	cout << -1 << '\n';
}

// https://www.geeksforgeeks.org/find-two-numbers-sum-xor/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}