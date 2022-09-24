#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

vector<vector<int>> findBeforeMatrix(vector<vector<int>> &after) {
	int n = after.size(), m = after[0].size();
	vector<vector<int>> before(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int left = (j > 0 ? after[i][j - 1] : 0);
			int up = (i > 0 ? after[i - 1][j] : 0);
			int diagonal = (i > 0 and j > 0 ? after[i - 1][j - 1] : 0);
			before[i][j] = after[i][j] - left - up + diagonal;
		}
	}

	return before;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> after(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> after[i][j];
		}
	}

	vector<vector<int>> ans = findBeforeMatrix(after);
	debug(ans)
	return 0;
}