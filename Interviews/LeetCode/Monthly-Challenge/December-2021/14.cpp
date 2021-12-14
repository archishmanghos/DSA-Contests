void trav(TreeNode *root, int &low, int &high, int &ans)
{
    if(root == NULL)
        return;
    if(root->val >= low && root->val <= high)
        ans += root->val;
    trav(root->left, low, high, ans);
    trav(root->right, low, high, ans);
}
int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    trav(root, low, high, ans);
    return ans;
}