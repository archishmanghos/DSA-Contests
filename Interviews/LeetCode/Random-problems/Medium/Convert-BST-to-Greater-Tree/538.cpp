void convertToGreater(TreeNode *root, int &valTillNow){
    if(!root){
        return;
    }
    
    convertToGreater(root->right, valTillNow);
    valTillNow += root->val;
    root->val = valTillNow;
    convertToGreater(root->left, valTillNow);
}

TreeNode *convertBST(TreeNode *root){
    int valTillNow = 0;
    convertToGreater(root, valTillNow);
    return root;
}