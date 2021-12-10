int dp(int n, vector<int> &cache, int &mod)
{
    if(n <= 2)
        return max((int)1, n);
    if(cache[n] != -1)
        return cache[n];
    int ans = ((2 * (dp(n - 1, cache, mod) % mod)) % mod + dp(n - 3, cache, mod) % mod) % mod;
    return cache[n] = ans;
}
int numTilings(int n)
{
    vector<int> cache(n + 5, -1);
    int mod = 1e9 + 7;
    return dp(n, cache, mod);
}