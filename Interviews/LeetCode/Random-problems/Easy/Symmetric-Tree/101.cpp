bool checkSymmetric(TreeNode* root1, TreeNode* root2) {
    if (!root1 or !root2) return root1 == root2;
    return (root1->val == root2->val and checkSymmetric(root1->left, root2->right) and checkSymmetric(root1->right, root2->left));
}

bool isSymmetric(TreeNode* root) {
    return checkSymmetric(root->left, root->right);
}