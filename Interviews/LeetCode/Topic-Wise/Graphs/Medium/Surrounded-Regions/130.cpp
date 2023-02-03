#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int n = board.size(), m = board[0].size();
		queue<vector<int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
					if (board[i][j] == 'O') q.push({i, j});
				}
			}
		}

		while (!q.empty()) {
			int r = q.front()[0], c = q.front()[1];
			q.pop();
			board[r][c] = 'Z';
			int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
			auto valid = [&](int r, int c) {
				return (r >= 0 and r < n and c >= 0 and c < m);
			};
			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i], nc = c + dy[i];
				if (valid (nr, nc) and board[nr][nc] == 'O') q.push({nr, nc});
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == 'Z') board[i][j] = 'O';
			}
		}
	}
};