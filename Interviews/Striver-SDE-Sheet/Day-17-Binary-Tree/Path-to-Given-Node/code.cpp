void path(TreeNode* root, int B, vector<int> &ans) {
    if (!root) return;
    ans.push_back(root->val);
    if (root->val == B) return;
    path(root->left, B, ans);
    path(root->right, B, ans);
    if (ans.back() != B) {
        ans.pop_back();
    }
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    path(A, B, ans);
    return ans;
}