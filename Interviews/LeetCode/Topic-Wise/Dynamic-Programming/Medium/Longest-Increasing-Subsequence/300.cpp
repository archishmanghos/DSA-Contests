int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> lisNotLis;

    for (int i = 0; i < n; i++) {
        if (lisNotLis.size() == 0 or nums[i] > lisNotLis.back()) {
            lisNotLis.push_back(nums[i]);
        } else {
            int index = lower_bound(lisNotLis.begin(), lisNotLis.end(), nums[i]) - lisNotLis.begin();
            lisNotLis[index] = nums[i];
        }
    }

    return lisNotLis.size();
}