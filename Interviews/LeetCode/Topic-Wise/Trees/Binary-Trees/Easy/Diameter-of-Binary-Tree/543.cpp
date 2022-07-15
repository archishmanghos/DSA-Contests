int height(TreeNode* root, int &ans) {
    if (!root) return 0;
    int leftHeight = height(root->left, ans);
    int rightHeight = height(root->right, ans);
    ans = max(ans, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}
int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0, heightTree = height(root, ans);
    return ans;
}