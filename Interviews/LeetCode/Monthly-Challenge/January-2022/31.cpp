int maximumWealth(vector<vector<int>> &accounts)
{
    int ans = 0, n = accounts.size(), m = accounts[0].size();
    for(int i = 0; i < n; i++)
    {
        int wealth = 0;
        for(int j = 0; j < m; j++)
        {
            wealth += accounts[i][j];
        }
        ans = max(ans, wealth);
    }
    return ans;
}