#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool dfs(int r, int c, int idx, int n, int m, vector<vector<char>>& board, string& word) {
        if (idx == word.size() - 1)
            return true;

        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr < 0 or nr == n or nc < 0 or nc == m)
                continue;
            if (board[nr][nc] == '0')
                continue;
            if (board[nr][nc] == word[idx + 1]) {
                char temp = board[nr][nc];
                board[nr][nc] = '0';
                if (dfs(nr, nc, idx + 1, n, m, board, word))
                    return true;
                board[nr][nc] = temp;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    char temp = board[i][j];
                    board[i][j] = '0';
                    if (dfs(i, j, 0, n, m, board, word))
                        return true;
                    board[i][j] = temp;
                }
            }
        }

        return false;
    }
};