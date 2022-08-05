int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    vector<double> cache(target + 1, 0);
    for (int i = 0; i <= target; i++) {
        if (i == 0) cache[i] = 1;
        else {
            for (int j = 0; j < n; j++) {
                if (nums[j] <= i) {
                    cache[i] += cache[i - nums[j]];
                }
            }
        }
    }

    return (int)cache[target];
}