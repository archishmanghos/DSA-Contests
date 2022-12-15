#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	char grid[n][m];
	vector<int> row(n, 0), col(m, 0);
	for (int i = 0; i < n; i++) {
		bool allRed = true;
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			allRed &= grid[i][j] == '.';
		}
		row[i] |= allRed;
	}

	for (int i = 0; i < m; i++) {
		bool allRed = true;
		for (int j = 0; j < n; j++) {
			allRed &= grid[j][i] == '.';
		}
		col[i] |= allRed;
	}

	for (int i = 0; i < n; i++) {
		if (!row[i]) {
			for (int j = 0; j < m; j++) {
				if (!col[j]) {
					cout << grid[i][j];
				}
			}
			cout << '\n';
		}
	}

	return 0;
}