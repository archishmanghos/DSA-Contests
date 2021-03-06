vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans(numRows);
    for(int j = 0; j < numRows; j++)
    {
        ans[j].resize(j + 1);
        ans[j][0] = ans[j][j] = 1;
        if(j > 1)
            for(int i = 0; i < ans[j - 1].size() - 1; i++)
                ans[j][i + 1] = ans[j - 1][i + 1] + ans[j - 1][i];
    }
    return ans;
}