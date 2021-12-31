bool ancestor(TreeNode *root, int target, int &x)
{
    if(root == NULL)
        return false;
    if(root->val == target)
        return true;
    if(ancestor(root->left, target, x) || ancestor(root->right, target, x))
    {
        x = max(x, abs((root->val) - target));
        return true;
    }
    return false;
}
void inordertrav(TreeNode *root, TreeNode *rootFixed, int &ans)
{
    if(root == NULL)
        return;
    inordertrav(root->left, rootFixed, ans);
    int x = INT_MIN;
    ancestor(rootFixed, root->val, x);
    ans = max(ans, x);
    inordertrav(root->right, rootFixed, ans);
}
int maxAncestorDiff(TreeNode *root)
{
    int ans = INT_MIN;
    inordertrav(root, root, ans);
    return ans;
}