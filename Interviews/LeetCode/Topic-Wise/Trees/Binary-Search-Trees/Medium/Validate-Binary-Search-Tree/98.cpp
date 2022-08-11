bool validate(TreeNode* root, int64_t low, int64_t high) {
    if (!root) return true;
    if (1LL * root->val < low or 1LL * root->val > high) return false;
    bool leftTree = validate(root->left, low, 1LL * root->val - 1);
    bool rightTree = validate(root->right, 1LL * root->val + 1, high);
    return leftTree and rightTree;
}
bool isValidBST(TreeNode* root) {
    return validate(root, INT_MIN, INT_MAX);
}