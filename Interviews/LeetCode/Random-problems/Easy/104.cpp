int maxHeight(TreeNode *root) {
    if (!root) {
        return 0;
    }

    return 1 + max(maxHeight(root->left), maxHeight(root->right));
}

int maxDepth(TreeNode *root) {
    return maxHeight(root);
}