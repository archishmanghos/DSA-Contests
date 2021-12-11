int nthMagicalNumber(int n, int a, int b)
{
    int mod = 1e9 + 7, lcm = (a * b) / __gcd(a, b);
    long long low = (long long)min(a, b), high = (long long)n * min(a, b), mid;
    while(low < high)
    {
        mid = low + (high - low) / 2;
        int factors = mid / a + mid / b - mid / lcm;
        if(factors < n)
            low = mid + 1;
        else
            high = mid;
    }
    int ans = low % mod;
    return ans;
}