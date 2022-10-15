#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int sum(vector<int> &A, int l, int r) {
	int sum = 0;
	for (int i = l; i <= r; i++) {
		sum += A[i];
		if (sum < 0) {
			return 0;
		}
	}

	return sum;
}

void solve() {
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			ans += sum(A, i, j);
		}
	}

	cout << ans << '\n';
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