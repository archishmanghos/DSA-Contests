#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<int> rowOne (n, 0), colOne (m, 0);
		for (int i = 0; i < n; i++) {
			int one = 0;
			for (int j = 0; j < m; j++) one += grid[i][j] == 1;
			rowOne[i] = one;
		}

		for (int i = 0; i < m; i++) {
			int one = 0;
			for (int j = 0; j < n; j++) one += grid[j][i] == 1;
			colOne[i] = one;
		}

		vector<vector<int>> ans (n, vector<int> (m, 0));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[i][j] = 2 * rowOne[i] - n + 2 * colOne[j] - m;
		return ans;
	}
};