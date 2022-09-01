void goodNodes(TreeNode* root, int maxVal, int &ans) {
    if (!root) return;
    if (maxVal <= root->val) ans += 1;
    maxVal = max(maxVal, root->val);
    goodNodes(root->left, maxVal, ans);
    goodNodes(root->right, maxVal, ans);
}
int goodNodes(TreeNode* root) {
    int ans = 0;
    goodNodes(root, INT_MIN, ans);
    return ans;
}