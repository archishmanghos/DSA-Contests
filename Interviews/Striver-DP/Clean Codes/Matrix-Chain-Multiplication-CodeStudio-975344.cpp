#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<vector<int>> cache(n, vector<int>(n, 0));
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i; j <= n - 1; j++) {
			if (i == j) cache[i][j] = 0;
			else {
				int ans = 1e9;
				for (int k = i; k < j; k++) {
					ans = min(ans, cache[i][k] + cache[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
				}
				cache[i][j] = ans;
			}
		}
	}

	cout << cache[1][n - 1];
	return 0;
}