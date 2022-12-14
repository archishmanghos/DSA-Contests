#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, sum = 0; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		sum += a;
	}

	cout << max(-1, n - sum);
	return 0;
}