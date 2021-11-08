int cache[205][205];
int dp(int x, int y, int &n, int &m, vector<vector<int>> &a)
{
    if(x == n - 1 && y == m - 1)
        return (a[x][y] <= 0 ? (-a[x][y] + 1) : 1);
    if(x >= n || y >= m)
        return 20000;
    if(cache[x][y] != -1)
        return cache[x][y];

    int ans = min(dp(x + 1, y, n, m, a), dp(x, y + 1, n, m, a)) - a[x][y];
    return cache[x][y] = (ans <= 0 ? 1 : ans);
}
int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int n = dungeon.size();
    int m = dungeon[0].size();
    memset(cache, -1, sizeof(cache));
    int ans = dp(0, 0, n, m, dungeon);
    return ans;
}

/*

Analysis: 

Time-Complexity: O(N*M)
Space-Complexity: O(N*M)

Easy Dynammic Programming approach. Be careful when to take negative value as result and when to make it 1. 

*/