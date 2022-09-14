int dfs(TreeNode* root, int mask) {
    if (!root) return 0;

    mask ^= (1 << (root->val));
    if (!root->left and !root->right) {
        int odd = __builtin_popcount(mask);
        mask ^= (1 << (root->val));

        return odd <= 1;
    }


    int leftTree = dfs(root->left, mask);
    int rightTree = dfs(root->right, mask);
    mask ^= (1 << (root->val));

    return leftTree + rightTree;
}

int pseudoPalindromicPaths (TreeNode* root) {
    return dfs(root, 0);
}