TreeNode *constructBST(int ub, int &index, vector<int> &preorder){
    TreeNode *root = NULL;
    if(index < preorder.size()){
        if(preorder[index] < ub) root = new TreeNode(preorder[index]);
        if(root){
            index++;
            root->left = constructBST(root->val, index, preorder);
            root->right = constructBST(ub, index, preorder);
        }
    }
    
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return constructBST(INT_MAX, index, preorder);
}