#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	string pi = "314159265358979323846264338327";
	string S; cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != pi[i]) {
			cout << i << '\n';
			return;
		}
	}

	cout << S.size() << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}