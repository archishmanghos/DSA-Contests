#include <bits/stdc++.h>
#define int long long
using namespace std;

int K;
string S;

void solve() {
	cin >> K >> S;
	string T = "FBFFBFFBFBFFBFFBFBFFBFFB";
	for (int i = 0; i < T.size(); i++) {
		if (i + K <= T.size()) {
			if (T.substr(i, K) == S) {
				cout << "YES" << '\n';
				return;
			}
		}
	}

	cout << "NO" << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}