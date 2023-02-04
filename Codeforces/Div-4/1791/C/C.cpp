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
	int i = 0, j = N - 1;
	while (i < j) {
		if (S[i] != S[j]) {
			i += 1;
			j -= 1;
		} else break;
	}

	cout << (j - i + 1) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}