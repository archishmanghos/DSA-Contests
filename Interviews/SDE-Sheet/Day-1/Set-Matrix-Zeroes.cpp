// brute, TC = O(N * M * (N + M)), SC = O(N*M)

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<pair<int, int>> pos;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == 0)
                pos.push_back({i, j});

    for(pair<int, int> i : pos)
    {
        for(int k = 0; k < n; k++)
            matrix[k][i.second] = 0;
        for(int k = 0; k < m; k++)
            matrix[i.first][k] = 0;
    }
}

// better brute, TC = O(N * M + N * M), SC = O(N + M)

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> dummyColumn(n, 1), dummyRow(m, 1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == 0)
                dummyColumn[i] = dummyRow[j] = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            matrix[i][j] = (dummyColumn[i] == 0 || dummyRow[j] == 0 ? 0 : matrix[i][j]);
}

// most optimal, TC = O(N * M + N * M), SC = O(1)

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bool cell00 = true;
    for(int i = 0; i < n; i++)
    {
        if(matrix[i][0] == 0)
            cell00 = false;
        for(int j = 1; j < m; j++)
            if(matrix[i][j] == 0)
                matrix[0][j] = matrix[i][0] = 0;
    }

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 1; j--)
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        if(!cell00)
            matrix[i][0] = 0;
    }
}