string longestPalindrome(string s)
{
    string s1 = "";
    for(int i = 0; i < s.size(); i++)
    {
        s1 += '$';
        s1 += s[i];
    }
    s1 += '$';
    s = s1;
    int n = s.size();
    vector<int> odd(n, 0);
    for(int i = 0; i < n; i++)
    {
        while(i - odd[i] >= 0 && i + odd[i] < n && (s[i - odd[i]] == s[i + odd[i]]))
            odd[i] += 1;
    }
    string oddS = "";
    pair<int, int> maxx = {INT_MIN, -1};
    for(int i = 0; i < n; i++)
    {
        if(odd[i] > maxx.first)
        {
            maxx.first = odd[i];
            maxx.second = i;
        }
    }
    oddS = s[maxx.second--];
    maxx.first -= 1;
    while(maxx.first--)
    {
        oddS = s[maxx.second] + oddS + s[maxx.second];
        maxx.second -= 1;
    }
    string ans = "";
    for(int i = 1; i < oddS.size(); i += 2)
        ans += oddS[i];
    return ans;
}