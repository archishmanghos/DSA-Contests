int binarytointeger(string x)
{
    int ans = 0, m = 1;
    for(int i = x.size() - 1; i >= 0; i--)
    {
        ans += (x[i] - '0') * m;
        m <<= 1;
    }
    return ans;
}
void trav(TreeNode *root, int &ans, string s)
{
    if(root == NULL)
        return;

    s += ((root->val) + '0');
    if(root->left or root->right)
    {
        trav(root->left, ans, s);
        trav(root->right, ans, s);
    }
    else
        ans += binarytointeger(s);
}
int sumRootToLeaf(TreeNode *root)
{
    int ans = 0;
    string s = "";
    trav(root, ans, s);
    return ans;
}