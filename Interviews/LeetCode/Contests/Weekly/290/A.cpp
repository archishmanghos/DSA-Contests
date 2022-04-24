vector<int> intersection(vector<vector<int>> &nums){
    vector<int> cnt(1005, 0);
    for(int i = 0; i < nums.size(); i++){
        for(int j : nums[i]){
            cnt[j] += 1;
        }
    }
    
    int n = nums.size();
    vector<int> ans;
    for(int i = 1; i <= 1000; i++){
        if(cnt[i] == n){
            ans.push_back(i);
        }
    }
    
    return ans;
}