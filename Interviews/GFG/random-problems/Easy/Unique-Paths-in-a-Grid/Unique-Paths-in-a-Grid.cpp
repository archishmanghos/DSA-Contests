#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dp (int r, int c, vector<vector<int>> &grid, vector<vector<int>> &cache) {
		if (r == grid.size() - 1 and c == grid[0].size() - 1) return 1;
		if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size()) return 0;
		if (grid[r][c] == 0) return 0;
		int &answer = cache[r][c], MOD = 1e9 + 7;
		if (answer != -1) return answer;

		answer = 0;
		answer = (answer + dp (r + 1, c, grid, cache) % MOD) % MOD;
		answer = (answer + dp (r, c + 1, grid, cache) % MOD) % MOD;
		return answer;
	}

	int uniquePaths(int n, int m, vector<vector<int>> &grid) {
		if (!grid[0][0] or !grid[n - 1][m - 1]) return 0;
		vector<vector<int>> cache (n, vector<int> (m, -1));
		return dp (0, 0, grid, cache);
	}
};