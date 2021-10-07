int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool rec(vector<vector<char>> &board, int idx, int x, int y, int &n, int &m, string &word)
{
    if(x >= n || x < 0)
        return false;
    if(y >= m || y < 0)
        return false;
    if(word[idx] != board[x][y])
        return false;
    if(idx == word.size() - 1)
        return true;

    char cur = board[x][y];
    board[x][y] = '*';
    bool ans = false;
    for(int i = 0; i < 4; i++)
        ans |= rec(board, idx + 1, x + dx[i], y + dy[i], n, m, word);
    board[x][y] = cur;
    return ans;
}
bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(rec(board, 0, i, j, n, m, word))
                return true;
        }
    }
    return false;
}

/*

Analysis:

Time-Complexity: Hard to determine, recursive tree
Space-Complexity: O(1)

Tricky recursive solution, especially because words can start anywhere in the grid.

*/