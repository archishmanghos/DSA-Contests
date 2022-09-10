bool checkPossibility(vector<int>& nums) {
    vector<int> lis;
    for (int i = 0; i < nums.size(); i++) {
        if (lis.size() == 0 or nums[i] >= lis.back()) {
            lis.push_back(nums[i]);
        } else {
            int index = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            lis[index] = nums[i];
        }
    }

    return (lis.size() >= (nums.size() - 1));
}