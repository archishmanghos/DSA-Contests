int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int start = int(-1e6), ans = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] - start <= k) continue;
        else start = nums[i], ans += 1;
    }

    return ans;
}