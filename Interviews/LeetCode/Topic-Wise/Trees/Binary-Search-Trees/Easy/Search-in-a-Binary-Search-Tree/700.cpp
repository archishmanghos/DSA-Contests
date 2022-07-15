TreeNode *searchBST(TreeNode *root, int val){
    while(root and root->val != val){
        root = (val < root->val ? root->left : root->right);
    }
    
    return root;
}