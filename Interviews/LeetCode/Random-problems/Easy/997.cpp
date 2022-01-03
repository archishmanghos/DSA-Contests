int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> cnt(n + 2, 0);
    for(auto i : trust)
    {
        cnt[i[0]] -= 1;
        cnt[i[1]] += 1;
    }

    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == n - 1)
            return i;
    }
    return -1;
}