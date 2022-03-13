void fun(TreeNode *root, TreeNode *parent, int &ans){
    bool add = false;
    if(parent and parent->val % 2 == 0){
        add = true;
    }
    if(root->left){
        ans += (add ? root->left->val : 0);
        fun(root->left, root, ans);
    }
    if(root->right){
        ans += (add ? root->right->val : 0);
        fun(root->right, root, ans);
    }
}
int sumEvenGrandparent(TreeNode *root){
    int ans = 0;
    fun(root, NULL, ans);
    return ans;
}