int depth(TreeNode* root) {
    if (!root->left and !root->right) return 1;
    return 1 + min(root->left ? minDepth(root->left) : INT_MAX, root->right ? minDepth(root->right) : INT_MAX);
}
int minDepth(TreeNode* root) {
    return (root ? depth(root) : 0);
}