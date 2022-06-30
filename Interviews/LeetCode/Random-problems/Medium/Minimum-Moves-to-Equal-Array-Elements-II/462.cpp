int minMoves2(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0, l = 0, r = n - 1;
    while (l < r) {
        ans += nums[r--] - nums[l++];
    }

    return ans;
}