int heightBalanced(TreeNode* root, bool &ans) {
    if (!root) return 0;
    int leftHeight = heightBalanced(root->left, ans);
    int rightHeight = heightBalanced(root->right, ans);
    ans &= abs(leftHeight - rightHeight) <= 1;
    return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(TreeNode* root) {
    bool ans = true;
    int height = heightBalanced(root, ans);
    return ans;
}