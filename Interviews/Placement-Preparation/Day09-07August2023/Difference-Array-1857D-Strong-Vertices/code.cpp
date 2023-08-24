#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	vector<vector<int>> v(n);
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) v[i] = {a[i] - b[i], i + 1};

	sort(v.begin(), v.end());
	vector<int> answer;
	answer.push_back(v[n - 1][1]);
	for (int i = n - 2; i >= 0; i--) {
		if (v[n - 1][0] == v[i][0]) answer.push_back(v[i][1]);
		else break;
	}

	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (int i : answer) cout << i << ' ';
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