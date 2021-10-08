int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int ans = 0, start = -1;
    vector<int> pos(300, -1);
    for(int i = 0; i < n; i++)
    {
        if(pos[s[i]] > start)
            start = pos[s[i]];
        pos[s[i]] = i;
        ans = max(ans, i - start);
    }
    return ans;
}

/*

Analysis:

Time-Complexity: O(N)
Space-Complexity: O(256)

Sliding-Window technique
*/
