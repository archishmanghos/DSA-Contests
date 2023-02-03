#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size(), maxx = 1e9;
		vector<vector<int>> dist (n, vector<int> (m, maxx));

		queue<vector<int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) {
					q.push({i, j});
					dist[i][j] = 0;
				}
			}
		}

		int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}, curDist = 1;
		while (!q.empty()) {
			auto valid = [&](int r, int c) {
				return (r >= 0 and r < n and c >= 0 and c < m);
			};

			int sz = q.size();
			while (sz--) {
				int r = q.front()[0], c = q.front()[1];
				q.pop();

				for (int i = 0; i < 4; i++) {
					if (valid (r + dx[i], c + dy[i]) and dist[r + dx[i]][c + dy[i]] == maxx) {
						dist[r + dx[i]][c + dy[i]] = curDist;
						q.push({r + dx[i], c + dy[i]});
					}
				}
			}

			curDist += 1;
		}

		return dist;
	}
};