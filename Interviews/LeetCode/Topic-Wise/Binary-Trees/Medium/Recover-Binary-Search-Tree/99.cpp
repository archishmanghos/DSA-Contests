void recoverBST(TreeNode *root, TreeNode *&pre, pair<pair<TreeNode *, TreeNode *>, TreeNode *> &swappedNodes){
    if(!root){
        return;
    }
    
    recoverBST(root->left, pre, swappedNodes);
    if(pre and root->val < pre->val){
        if(!swappedNodes.first.first){
            swappedNodes.first = {pre, root};
        }else{
            swappedNodes.second = root;
        }
    }
    pre = root;
    recoverBST(root->right, pre, swappedNodes);
}

void recoverTree(TreeNode *root){
    pair<pair<TreeNode *, TreeNode *>, TreeNode *> swappedNodes = {{NULL, NULL}, NULL};
    TreeNode *pre = NULL;
    recoverBST(root, pre, swappedNodes);
    if(!swappedNodes.second){
        swap(swappedNodes.first.first->val, swappedNodes.first.second->val);
    }else{
        swap(swappedNodes.first.first->val, swappedNodes.second->val);
    }
}