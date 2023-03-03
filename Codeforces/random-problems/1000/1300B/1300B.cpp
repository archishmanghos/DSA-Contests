#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, A[200200];

void solve() {
	cin >> N;
	for (int i = 1; i <= 2 * N; i++) cin >> A[i];
	sort(A + 1, A + 2 * N + 1);

	cout << (A[N + 1] - A[N]) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}