int findPairs(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    set <pair<int, int>> ans;
    for (int i = 0; i < nums.size(); i++) {
        auto index = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + k);
        if (index == nums.end()) {
            break;
        }
        if (nums[index - nums.begin()] == nums[i] + k) {
            ans.insert({nums[i], nums[index - nums.begin()]});
        }
    }
    return ans.size();
}