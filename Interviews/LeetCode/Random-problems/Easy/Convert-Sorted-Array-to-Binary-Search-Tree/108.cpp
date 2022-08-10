TreeNode* construct(int low, int high, vector<int> &nums) {
    if (low > high) return NULL;

    int mid = low + (high - low) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root -> left = construct(low, mid - 1, nums);
    root -> right = construct(mid + 1, high, nums);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return construct(0, nums.size() - 1, nums);
}