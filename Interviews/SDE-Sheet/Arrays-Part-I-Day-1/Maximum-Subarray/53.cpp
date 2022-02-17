int maxSubArray(vector<int> &nums) {
    int ans = -100000, maxTillNow = 0;
    for (int i = 0; i < nums.size(); i++) {
        maxTillNow += nums[i];
        ans = max(ans, maxTillNow);
        maxTillNow = max((int) 0, maxTillNow);
    }
    return ans;
}