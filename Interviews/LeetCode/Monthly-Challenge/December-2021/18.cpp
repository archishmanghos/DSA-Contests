string integertostring(long long x)
{
    string ans = "";
    while (x > 0)
    {
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
long long raisedto(long long a, long long b)
{
    long long res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
long long atMostNGivenDigitSet(vector<string> &digits, long long n)
{
    long long ans = 0, dsz = digits.size();
    string n1 = integertostring(n);
    long long digit = n1.size();
    for(long long i = 2; i <= digit; i++)
        ans += raisedto(dsz, i - 1);

    for(long long i = 0; i < digit; i++)
    {
        bool flag = true;
        for(string j : digits)
        {
            if(j[0] < n1[i])
                ans += raisedto(dsz, digit - i - 1);
            else if(j[0] == n1[i])
                flag = false;
        }
        if(flag)
            return ans;
    }
    return ans + 1;
}