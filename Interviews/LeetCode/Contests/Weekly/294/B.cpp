int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int ans = 0, n = capacity.size();
    vector<int> v;
    for(int i = 0; i < n; i++) v.push_back(capacity[i] - rocks[i]);
    
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if(additionalRocks >= v[i]) ans += 1, additionalRocks -= v[i];
    }
    
    return ans;
}