int cache[50];
int dp(int now, int &n)
{
    if(now >= n - 1)
        return 1;
    if(cache[now] != -1)
        return cache[now];

    int ans = dp(now + 1, n) + dp(now + 2, n);
    return cache[now] = ans;
}
int climbStairs(int n)
{
    memset(cache, -1, sizeof(cache));
    int ans = dp(0, n);
    return ans;
}

/*

Analysis:
Time-Complexity: O(N)
Space-Complexity: O(N)

Easy Dynammic Programming problem.

*/