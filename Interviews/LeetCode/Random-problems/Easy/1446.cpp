int maxPower(string s)
{
    int i = 0, j = 0, ans = 1;
    while(j < s.size())
    {
        if(s[j] == s[i])
            j += 1;
        else
        {
            ans = max(ans, j - i);
            i = j;
        }
    }
    ans = max(ans, j - i);
    return ans;
}