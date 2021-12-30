int smallestRepunitDivByK(int k)
{
    int rem = 0, ans = 0, N = 0;
    while(ans < k)
    {
        N = rem * 10 + 1;
        rem = N % k;
        ans += 1;
        if(rem == 0)
            return ans;
    }
    return -1;
}