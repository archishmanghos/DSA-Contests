int largestCombination(vector<int>& candidates) {
    vector<int> cnt(30, 0);
    for(int i = 0; i < candidates.size(); i++){
        for(int j = 0; j < 30; j++){
            if((candidates[i] & (1 << j))) cnt[j]++;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 30; i++) ans = max(ans, cnt[i]);
    return ans;
}