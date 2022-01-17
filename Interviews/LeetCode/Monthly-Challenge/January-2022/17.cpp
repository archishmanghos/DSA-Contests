bool wordPattern(string pattern, string s)
{
    map<string, string> mp;
    s += ' ';
    int j = 0, n = s.size(), cntWords = 0;
    string t = "";
    for(int i = 0; i < n; i++)
    {
        if(s[i] == ' ')
        {
            string x = to_string(pattern[j]);
            if(mp.find(x) == mp.end() and mp.find(t) == mp.end())
            {
                mp[x] = t;
                mp[t] = x;
            }
            else
            {
                if(mp[x] != t)
                    return false;
            }
            t = "";
            j += 1;
            cntWords += 1;
        }
        else
            t += s[i];
    }

    return (cntWords == (int)pattern.size());
}