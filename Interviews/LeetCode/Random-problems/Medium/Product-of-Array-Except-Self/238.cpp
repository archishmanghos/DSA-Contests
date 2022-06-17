vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size(), prodFromStart = 1, prodFromEnd = 1;
    vector<int> ans(n, 1);

    for(int i = 0; i < n; i++){
        ans[i] *= prodFromStart, prodFromStart *= nums[i];
        ans[n - i - 1] *= prodFromEnd, prodFromEnd *= nums[n - i - 1];
    }

    return ans;
}