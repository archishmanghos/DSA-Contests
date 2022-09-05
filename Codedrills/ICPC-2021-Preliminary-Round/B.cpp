#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {

	int N, X;
	string S; cin >> N >> X >> S;
	vector<int> v;
	int cnt0 = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			if (cnt0 > 0) v.push_back(cnt0);
			cnt0 = 0;
			ans += 1;
		} else {
			cnt0 += 1;
		}
	}
	if (cnt0 > 0) v.push_back(cnt0);

	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--) {
		if (2 * v[i] + 1 <= X) {
			ans += v[i];
			X -= (2 * v[i] + 1);
		} else {
			int canBe = (X - 1) / 2;
			ans += canBe;
			break;
		}
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}