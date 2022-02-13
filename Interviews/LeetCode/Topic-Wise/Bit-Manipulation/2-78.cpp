vector <vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();
    vector <vector<int>> ans((1 << n));

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                ans[i].push_back(nums[j]);
            }
        }
    }

    return ans;
}