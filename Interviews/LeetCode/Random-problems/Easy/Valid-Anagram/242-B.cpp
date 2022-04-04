bool isAnagram(string s, string t){
    if(s.size() != t.size()){
        return false;
    }
    vector<int> cnt(26, 0);
    for(int i = 0; i < s.size(); i++){
        cnt[s[i] - 'a'] += 1;
        cnt[t[i] - 'a'] -= 1;
    }
    
    bool ans = true;
    for(int i = 0; i < 26; i++){
        ans &= cnt[i] == 0;
    }
    
    return ans;
}