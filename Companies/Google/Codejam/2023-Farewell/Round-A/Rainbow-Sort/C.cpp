#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> sorted;
	int A[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	sorted.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		if (A[i] == A[i - 1]) continue;
		sorted.push_back(A[i]);
	}

	set<int> s;
	for (int i = 0; i < sorted.size(); i++) {
		if (s.find(sorted[i]) != s.end()) {
			cout << "IMPOSSIBLE" << '\n';
			return;
		}
		s.insert(sorted[i]);
	}

	for (int i : sorted) cout << i << ' ';
	cout << '\n';
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