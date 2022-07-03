int dp(int index, int preDiff, int &n, vector<int> &nums, vector<vector<int>> &cache){
    if(cache[index][preDiff] != -1) return cache[index][preDiff];

    int ans = 1;
    if(preDiff == 2){
        for(int i = index + 1; i < n; i++){
            if(nums[i] > nums[index]){
                ans = max(ans, dp(i, 0, n, nums, cache) + 1);
            }else if(nums[i] < nums[index]){
                ans = max(ans, dp(i, 1, n, nums, cache) + 1);
            }
        }
    }else if(preDiff){
        for(int i = index + 1; i < n; i++){
            if(nums[i] > nums[index]){
                ans = max(ans, dp(i, 0, n, nums, cache) + 1);
            }
        }
    }else{
        for(int i = index + 1; i < n; i++){
            if(nums[i] < nums[index]){
                ans = max(ans, dp(i, 1, n, nums, cache) + 1);
            }
        }
    }
    
    return cache[index][preDiff] = ans;
}
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> cache(n + 1, vector<int>(3, -1));
    return dp(0, 2, n, nums, cache);
}