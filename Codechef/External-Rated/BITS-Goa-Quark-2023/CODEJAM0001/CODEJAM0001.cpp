#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, K;

void solve() {
	cin >> N >> K;
	int X = N / K;
	vector<int> A(X, 0);
	vector<vector<int>> ans(X);
	int start = 1, i = 0, add = 1;
	while (start <= (N - X)) {
		ans[i].push_back(start);
		A[i] += start++;
		i += add;
		if (i == X) i = 0;
	}

	A[X - 1] += start;
	ans[X - 1].push_back(start);
	for (int i = X - 2; i >= 0; i--) {
		ans[i].push_back(A[X - 1] - A[i]);
	}

	for (int i = 0; i < X; i++) {
		int sum = 0;
		for (int j : ans[i]) cout << j << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}