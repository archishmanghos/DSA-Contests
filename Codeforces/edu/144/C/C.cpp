#include <bits/stdc++.h>
#define int long long
using namespace std;

int L, R;

void solve() {
	cin >> L >> R;
	int maxSize = 1, _L = L;
	while (_L * 2 <= R) {
		_L <<= 1;
		maxSize += 1;
	}

	cout << maxSize << ' ';
	int maxx = R, sz = maxSize - 1;
	while (sz--) maxx >>= 1;

	int answer = maxx - L + 1;
	sz = maxSize - 1, maxx = R;
	while (sz--) {
		if (sz == 0) maxx /= 3;
		else maxx >>= 1;
	}

	answer += max(0ll, (maxx - L + 1)) * (maxSize - 1);
	cout << answer << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}