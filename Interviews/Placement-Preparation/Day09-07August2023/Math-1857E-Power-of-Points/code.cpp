#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		a[i][1] = i;
	}
	sort(a.begin(), a.end());

	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i][0];
	int totalSum = sum;
	int answer[n];
	for (int i = 0; i < n; i++) {
		int right = sum + (n - i) * (1 - a[i][0]);
		int left = i * (1 + a[i][0]) - (totalSum - sum);
		answer[a[i][1]] = (left + right);
		sum -= a[i][0];
	}

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