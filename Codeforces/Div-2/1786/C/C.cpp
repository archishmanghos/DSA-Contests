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
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + N + 1);

	int answer = A[1] - 1, pre = 2;
	for (int i = 2; i <= N; i++) {
		int diff = max(0ll, (A[i] - pre));
		answer += diff;
		A[i] -= diff;
		pre = A[i] + 1;
	}

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