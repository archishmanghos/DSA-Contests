int tilt(TreeNode *root, int &ans)
{
    if(root == NULL)
        return 0;
    int child1 = tilt(root->left, ans);
    int child2 = tilt(root->right, ans);
    ans += abs(child1 - child2);
    return (child1 + child2 + root->val);
}
int findTilt(TreeNode *root)
{
    int ans = 0;
    int sum = tilt(root, ans);
    return ans;
}