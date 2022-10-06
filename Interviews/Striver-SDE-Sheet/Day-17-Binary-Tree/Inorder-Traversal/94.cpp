void traverse(TreeNode* root, vector<int> &ans) {
    if (!root) return;
    traverse(root->left, ans);
    ans.push_back(root->val);
    traverse(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse(root, ans);
    return ans;
}