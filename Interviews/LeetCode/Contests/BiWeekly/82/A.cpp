bool evaluateTree(TreeNode* root) {
       if(!root->left and !root->right) return root->val;
        return (root->val == 2 ? evaluateTree(root->left) or evaluateTree(root->right) : evaluateTree(root->left) and evaluateTree(root->right));
}