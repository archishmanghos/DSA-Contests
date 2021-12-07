// brute, TC = O(N * M * (N + M)), SC = O(N*M)

/*The brute force is fairly normal, we just take a vector
and store the positions where the matrix has 0. We then iterate
over the matrix again, and whenever we find a zero, we traverse the row and column and make the cells in them 0 too.*/

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

/*The brute method is bettered by taking 2 1-D arrays representing
a dummy row and a dummy column. Whenever, we encounter 
a 0 in the cell, we update the i-th cell of the column matrix with 0 
and the j-th cell of the row matrix with 0. 
In the next traversal, we check if either of i and j of the row and column matrix are 0, 
if found, we make the cell 0*/

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

/*This method is an optimisation of the previous method. We don't take the dummy arrays, 
and instead make the 1st row and column the dummy matrices. 
We assign a column variable to check if the lower column or the right row is making the [0,0] cell 0. 
In that case, we modify the bool variable, such that the other cells don't get affected. 
Take care to traverse the 2nd time backwards.*/

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