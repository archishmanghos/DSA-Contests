vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prodPrefix(n, nums[0]), prodSuffix(n, nums.back()), ans(n);

    for(int i = 1; i < n; i++) prodPrefix[i] = nums[i] * prodPrefix[i - 1];
    for(int i = n - 2; i >= 0; i--) prodSuffix[i] = nums[i] * prodSuffix[i + 1];

    for(int i = 0; i < n; i++){
        int leftProduct = (i > 0 ? prodPrefix[i - 1] : 1);
        int rightProduct = (i < n - 1 ? prodSuffix[i + 1] : 1);
        ans[i] = leftProduct * rightProduct;
    }

    return ans;
}