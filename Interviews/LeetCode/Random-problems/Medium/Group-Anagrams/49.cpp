vector<vector<string>> groupAnagrams(vector<string> &strs){
    map<vector<int>, int> mp;
    int n = strs.size(), j = 0;
    vector<vector<string>> ans(n);
    for(int i = 0; i < n; i++){
        vector<int> cnt(26, 0);
        for(char c : strs[i]){
            cnt[c - 'a'] += 1;
        }
        if(mp.find(cnt) != mp.end()){
            ans[mp[cnt]].push_back(strs[i]);
        }else{
            ans[j].push_back(strs[i]);
            mp[cnt] = j++;
        }
    }
    ans.resize(j);
    return ans;
}