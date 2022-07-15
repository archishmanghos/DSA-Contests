TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* tempNode = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tempNode);
        return root;
}