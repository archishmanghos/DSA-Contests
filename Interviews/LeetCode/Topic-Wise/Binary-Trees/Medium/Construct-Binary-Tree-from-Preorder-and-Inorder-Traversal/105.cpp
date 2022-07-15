TreeNode *construct(int &preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &index){
    if(inStart > inEnd) return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);
    int indexInInorder = index[preorder[preStart]];
    preStart += 1;
    root->left = construct(preStart, inStart, indexInInorder - 1, preorder, inorder, index);
    root->right = construct(preStart, indexInInorder + 1, inEnd, preorder, inorder, index);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> index;
    for(int i = 0; i < inorder.size(); i++) index[inorder[i]] = i;
    int preStart = 0;
    return construct(preStart, 0, inorder.size() - 1, preorder, inorder, index);
}