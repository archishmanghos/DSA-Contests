int hammingDistance(int x, int y)
{
    int ans = 0;
    for(int i = 0; i < 31; i++)
    {
        int x1 = x & (1 << i);
        int y1 = y & (1 << i);
        ans += (x1 != y1);
    }
    return ans;
}