void dfs(TreeNode* root, vector<int> path, int sum, vector<vector<int>> &ans, int ts) {
    if (!root) return;

    path.push_back(root->val);
    sum += root->val;
    if (sum == ts and !root->left and !root->right) {
        ans.push_back(path);
    }

    dfs(root->left, path, sum, ans, ts);
    dfs(root->right, path, sum, ans, ts);
    path.pop_back();
    sum -= root->val;
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    dfs(root, {}, 0, ans, targetSum);
    return ans;
}