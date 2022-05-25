int lengthOfLongestSubstring(string s) {
    vector<int> index(100, -1);
    int start = 0, ans = 0, n = s.size();
    for(int i = 0; i < n; i++){
        if(index[s[i] - ' '] != -1) start = max(start, index[s[i] - ' '] + 1);
        ans = max(ans, i - start + 1);
        index[s[i] - ' '] = i;
    }
    
    return ans;
}