TreeNode *build(int l, int r, vector<int> &nums){
    if(l > r){
        return NULL;
    }
    int pos = l;
    for(int i = l; i <= r; i++){
        if(nums[i] > nums[pos]){
            pos = i;
        }
    }
    
    TreeNode *root = new TreeNode(nums[pos]);
    root->left = build(l, pos - 1, nums);
    root->right = build(pos + 1, r, nums);
    return root;
}
TreeNode *constructMaximumBinaryTree(vector<int> &nums){
    int l = 0, r = nums.size() - 1;
    return build(l, r, nums);
}