#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n, fee; cin >> n >> fee;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) cin >> prices[i];

	vector<int> curCache(2, 0);
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			curCache[0] = prices[i] - fee;
		} else {
			curCache[1] = max(curCache[0] - prices[i], curCache[1]);
			curCache[0] = max(curCache[1] + (prices[i] - fee), curCache[0]);
		}
	}

	cout << curCache[1];
	return 0;
}