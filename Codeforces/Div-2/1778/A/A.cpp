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
	int A[N + 2], sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		sum += A[i];
	}

	int plusMinus = 0;
	for (int i = 2; i <= N; i++) {
		if (A[i] == -1 and A[i - 1] == -1) {
			cout << sum + 4 << '\n';
			return;
		}
		plusMinus += A[i] != A[i - 1];
	}

	if (plusMinus) cout << sum << '\n';
	else cout << sum - 4 << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}