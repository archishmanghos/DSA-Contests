#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N, C; cin >> N >> C;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] += i + 1;
	}

	sort(A, A + N);
	for (int i = 0; i < N; i++) {
		if (A[i] <= C) C -= A[i];
		else {
			cout << i << '\n';
			return;
		}
	}

	cout << N << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}