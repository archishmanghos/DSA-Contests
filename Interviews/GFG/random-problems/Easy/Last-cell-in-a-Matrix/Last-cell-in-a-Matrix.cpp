#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	pair<int, int> endPoints(vector<vector<int>> matrix, int R, int C) {
		int i = 0, j = 0, dir = 0, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
		pair<int, int> lastCell;
		while (i >= 0 and i < R and j >= 0 and j < C) {
			if (matrix[i][j]) {
				matrix[i][j] = 0;
				dir = (dir + 1) % 4;
			}

			lastCell = {i, j};
			i += dx[dir], j += dy[dir];
		}

		return lastCell;
	}
};