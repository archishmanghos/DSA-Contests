int cache[50];
int dp(int n)
{
    if(cache[n] != -1)
        return cache[n];
    int ans = dp(n - 1) + dp(n - 2) + dp(n - 3);
    return cache[n] = ans;
}
int tribonacci(int n)
{
    memset(cache, -1, sizeof(cache));
    cache[0] = 0, cache[1] = cache[2] = 1;
    int ans = dp(n);
    return ans;
}