#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n, c; cin >> n >> c;
	vector<int> cuts(c + 1);
	for (int i = 0; i < c; i++) cin >> cuts[i];
	cuts[c] = n;
	sort(cuts.begin(), cuts.end());

	vector<vector<int>> cache(c + 2, vector<int>(c + 2, 0));
	for (int i = c + 1; i >= 0; i--) {
		for (int j = i + 2; j <= c + 1; j++) {
			int ans = 1e9;
			for (int k = i + 1; k < j; k++) {
				ans = min(ans, cache[i][k] + cache[k][j] + cuts[j - 1] - (i ? cuts[i - 1] : 0));
			}
			cache[i][j] = ans;
		}
	}

	cout << cache[0][c + 1];
	return 0;
}