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
	vector<pair<pair<string, int>, int>> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first.first >> A[i].first.second >> A[i].second;
		B[i] = A[i];
	}

	sort(A.begin(), A.end(), [](const pair<pair<string, int>, int> &a, const pair<pair<string, int>, int> &b) {
		if (a.first.first != b.first.first) return a.first.first < b.first.first;
		return a.second < b.second;
	});

	sort(B.begin(), B.end(), [](const pair<pair<string, int>, int> &a, const pair<pair<string, int>, int> &b) {
		if (a.first.second != b.first.second) return a.first.second < b.first.second;
		return a.second < b.second;
	});

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += A[i].second == B[i].second;
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