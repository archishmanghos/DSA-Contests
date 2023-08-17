#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		queue<int> q;
		int n = mat.size(), m = mat[0].size();
		vector<vector<int>> answer(n, vector<int> (m, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) {
					q.push(i * m + j);
					answer[i][j] = 0;
				}
			}
		}

		while (!q.empty()) {
			int it = q.front(); q.pop();
			int i = it / m, j = it % m;

			int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x >= 0 and y >= 0 and x < n and y < m) {
					if (answer[x][y] == -1) {
						answer[x][y] = answer[i][j] + 1;
						q.push(x * m + y);
					}
				}
			}
		}

		return answer;
	}
};