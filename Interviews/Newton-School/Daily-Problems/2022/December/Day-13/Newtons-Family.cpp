#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a; cin >> n;
	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n - 1; i++) {
		cin >> a;
		cnt[a] += 1;
	}

	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << '\n';
	}
	return 0;
}