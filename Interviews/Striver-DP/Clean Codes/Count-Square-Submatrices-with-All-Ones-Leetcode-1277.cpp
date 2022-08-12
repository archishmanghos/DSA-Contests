#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n, m; cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int> (m)), cache(n, vector<int>(m, 0));
	for (auto &all : matrix) {
		for (int &col : all) cin >> col;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 or j == 0) cache[i][j] = matrix[i][j];
			else {
				if (matrix[i][j] == 1) {
					cache[i][j] = 1 + min(cache[i - 1][j], min(cache[i][j - 1], cache[i - 1][j - 1]));
				}
			}
			ans += cache[i][j];
		}
	}

	cout << ans;
	return 0;
}