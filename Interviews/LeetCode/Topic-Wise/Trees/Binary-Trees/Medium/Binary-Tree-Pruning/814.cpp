bool makeNewTree(TreeNode* &root) {
    if (!root->left and !root->right) return root->val == 1;

    bool leftTree = false, rightTree = false;
    if (root->left) leftTree = makeNewTree(root->left);
    if (root->right) rightTree = makeNewTree(root->right);

    if (!leftTree) root->left = NULL;
    if (!rightTree) root->right = NULL;

    return leftTree or rightTree or root->val == 1;
}
TreeNode* pruneTree(TreeNode* root) {
    bool ans = makeNewTree(root);
    return ans ? root : NULL;
}