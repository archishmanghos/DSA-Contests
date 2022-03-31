int longestSubstring(string S){
    int ans = 0, n = S.size(), mask = 0;
    unordered_map<int, int> mp;
    mp[mask] = -1;
    
    for(int i = 0; i < n; i++){
        mask ^= (1 << (S[i] - 'a'));
        if(mp.find(mask) != mp.end()){
            ans = max(ans, i - mp[mask]);
        }else{
            mp[mask] = i;
        }
        
        for(int j = 0; j < 26; j++){
            if(mp.find((mask ^ (1 << j))) != mp.end()){
                ans = max(ans, i - mp[(mask ^ (1 << j))]);
            }
        }
    }
    
    return ans;
}