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
	N -= 1;
	int walice = 1, balice = 0, wbob = 0, bbob = 0, cur = 1;
	int i = 1, totalCards = 1, cnt = 0, oscillate = 1;
	while (N--) {
		if (cnt == 0) {
			if (i & 1) cur ^= 1;
			i += 1;
			cnt = i;
		}

		cnt--;
		oscillate ^= 1;
		if (cur) {
			if (oscillate) walice += 1;
			else balice += 1;
		} else {
			if (oscillate) wbob += 1;
			else bbob += 1;
		}
	}

	cout << (walice + balice) << ' ' << (wbob + bbob) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}