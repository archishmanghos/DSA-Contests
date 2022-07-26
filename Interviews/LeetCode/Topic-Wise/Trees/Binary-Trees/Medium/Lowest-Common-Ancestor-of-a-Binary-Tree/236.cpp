TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p or root == q) return root;
        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
        if ((leftNode == p and rightNode == q) or (leftNode == q and rightNode == p)) return root;
        if (leftNode) return leftNode;
        return rightNode;
}