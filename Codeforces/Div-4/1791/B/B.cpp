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
	string S; cin >> S;
	int i = 0, j = 0;
	for (int k = 0; k < N; k++) {
		if (S[k] == 'L') i -= 1;
		else if (S[k] == 'R') i += 1;
		else if (S[k] == 'U') j += 1;
		else j -= 1;
		if (i == 1 and j == 1) {
			cout << "YES" << '\n';
			return;
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