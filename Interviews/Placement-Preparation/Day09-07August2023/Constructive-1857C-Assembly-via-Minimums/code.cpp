#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	map<int, int> mp;
	int n1 = n * (n - 1) / 2;
	int A[n1];
	for (int i = 0; i < n1; i++) {
		cin >> A[i];
		++mp[A[i]];
	}

	int answer[n];
	for (int i = 0; i < n; i++) {
		int x = -1, red = 0;
		for (auto it : mp) {
			if (it.second >= (n - i - 1)) {
				x = it.first;
				red = n - i - 1;
				break;
			}
		}

		answer[i] = x;
		mp[x] -= red;
	}

	answer[n - 1] = answer[n - 2];
	for (int i = 0; i < n; i++) cout << answer[i] << ' ';
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