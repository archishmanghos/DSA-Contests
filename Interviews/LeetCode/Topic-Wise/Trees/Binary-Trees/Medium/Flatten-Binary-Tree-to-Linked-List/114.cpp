void construct(TreeNode* root, TreeNode* &prev) {
    if (!root) return;

    construct(root->right, prev);
    construct(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}
void flatten(TreeNode* root) {
    TreeNode* prev = NULL;
    construct(root, prev);
}