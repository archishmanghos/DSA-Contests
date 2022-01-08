int longestPalindrome(vector<string> &words)
{
    unordered_map<string, int> mp;
    for(string s : words)
        mp[s] += 1;

    int ans = 0;
    bool canTake = true;

    int n = words.size();

    for(int i = 0; i < n; i++)
    {
        string s = words[i];
        if(s[0] != s[1] and mp[s])
        {
            string t = "";
            t += s[1];
            t += s[0];
            if(mp[t])
            {
                ans += 4;
                mp[t] -= 1;
                mp[s] -= 1;
            }
        }
        else if(s[0] == s[1] and mp[s])
        {
            if(mp[s] > 1)
            {
                ans += (mp[s] / 2) * 4;
                mp[s] %= 2;
            }
            if(mp[s])
            {
                if(canTake)
                {
                    ans += 2;
                    canTake = false;
                    mp[s] -= 1;
                }
            }
        }
    }

    return ans;
}