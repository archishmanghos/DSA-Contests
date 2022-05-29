int rearrangeCharacters(string s, string target) {
    vector<int> cnt(26, 0), cnt1(26, 0);
    for(char c : s) cnt[c - 'a'] += 1;
    int ans = 1000;
    for(char c : target){
        cnt1[c - 'a'] += 1;
    }
    for(char c : target) ans = min(ans, cnt[c - 'a'] / cnt1[c - 'a']);
    
    return ans;
}