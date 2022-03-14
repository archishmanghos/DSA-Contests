TreeNode *fun(TreeNode *root, int &sum){
    if(root->right){
       fun(root->right, sum);
    }
    sum += root->val;
    root->val = sum;
    if(root->left){
        fun(root->left, sum);
    }
    return root;
}
TreeNode *bstToGst(TreeNode *root){
    int sum = 0;
    return fun(root, sum);
}