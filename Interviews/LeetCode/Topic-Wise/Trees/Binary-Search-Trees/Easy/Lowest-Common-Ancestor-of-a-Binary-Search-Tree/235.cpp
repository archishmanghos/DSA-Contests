TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((p->val < root->val and q->val > root->val) or (p->val > root->val and q->val < root->val)) return root;
        if (p == root or q == root) return root;
        return (p->val < root->val ? lowestCommonAncestor(root->left, p, q) : lowestCommonAncestor(root->right, p, q));
}