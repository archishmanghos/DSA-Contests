#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	vector<vector<int>> v(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		cin >> v[i][0];
		v[i][1] = i;
	}

	sort(v.begin(), v.end());
	int answer[N], B[N];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(B, B + N);

	for (int i = 0; i < N; i++) answer[v[i][1]] = B[i];
	for (int i = 0; i < N; i++) cout << answer[i] << ' ';
	cout << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}