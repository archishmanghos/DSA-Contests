void inorder(TreeNode *root, int &cnt, int &ans, int &k){
    if(!root or cnt == k){
        return;
    }
    
    inorder(root->left, cnt, ans, k);
    cnt += 1;
    if(cnt == k){
        ans = root->val;
        return;
    }
    inorder(root->right, cnt, ans, k);
}

int kthSmallest(TreeNode *root, int k){
    int ans, cnt = 0;
    inorder(root, cnt, ans, k);
    return ans;
}