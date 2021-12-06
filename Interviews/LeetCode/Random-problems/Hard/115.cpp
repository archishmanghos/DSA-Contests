int cache[1005][1005];
int dp(string s1, string t1, int n, int m)
{
    if(m == 0)
        return 1;
    if(n == 0)
        return 0;
    if(cache[n][m] != -1)
        return cache[n][m];

    int ans = 0;
    if(s1[n - 1] == t1[m - 1])
        ans = dp(s1, t1, n - 1, m - 1) + dp(s1, t1, n - 1, m);
    else
        ans = dp(s1, t1, n - 1, m);

    return cache[n][m] = ans;
}

int numDistinct(string s, string t)
{
    memset(cache, -1, sizeof(cache));
    int N = s.size(), M = t.size();
    int ans = dp(s, t, N, M);
    return ans;
}

/*

Analysis:
Time Complexity: O(3 * s.length * t.length), approximately
Space Complexity: O(s.length * t.length)

Classical DP problem of finding number of subsequences that match target string.
*/