#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	int i;
	for (i = 1; i <= 300000; i++) {
		if (i * 26 >= N) break;
		N -= i * 26;
	}

	cout << (char)((((N + i - 1) / i) - 1) + 'A') << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}