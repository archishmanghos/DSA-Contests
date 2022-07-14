bool isSameTree(TreeNode* p, TreeNode* q) {
       if(!p) return !q;
       if(!q) return !p;
       return isSameTree(p->left, q->left) and isSameTree(p->right, q->right) and p->val == q->val;
}