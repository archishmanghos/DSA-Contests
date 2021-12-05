int dp(int pre, TreeNode *root, map<pair<int, TreeNode *>, int> &cache)
{
    if(root == NULL)
        return 0;
    auto it = cache.find({pre, root});
    if(it != cache.end())
        return it->second;
    int ans;
    if(pre == 0)
        ans = max(dp(1, root->left, cache) + dp(1, root->right, cache) + root->val, dp(0, root->left, cache) + dp(0, root->right, cache));
    else
        ans = dp(0, root->left, cache) + dp(0, root->right, cache);
    cache.insert({{pre, root}, ans});
    return ans;
}
int rob(TreeNode *root)
{
    map<pair<int, TreeNode *>, int> cache;
    int ans = dp(0, root, cache);
    return ans;
}