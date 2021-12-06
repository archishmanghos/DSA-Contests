vector<int> partitionLabels(string s)
{
    vector<int> end(30, -1);
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(end[s[i] - 'a'] == -1)
            end[s[i] - 'a'] = i;
    }

    int i = 0;
    vector<int> ans;
    while(i < s.size())
    {
        int j = end[s[i] - 'a'], k = i;
        while(k < j)
        {
            if(end[s[k] - 'a'] > j)
                j = end[s[k] - 'a'];
            k += 1;
        }
        ans.push_back(j - i + 1);
        i = j + 1;
    }
    return ans;
}