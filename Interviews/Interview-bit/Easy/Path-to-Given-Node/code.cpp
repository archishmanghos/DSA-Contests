bool printPath(TreeNode* root, int node, vector<int> &path) {
    if (!root) return false;
    path.push_back(root->val);
    if (root->val == node) return true;

    bool nodeFound = printPath(root->left, node, path) or printPath(root->right, node, path);
    if (!nodeFound) path.pop_back();
    return nodeFound;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    bool ans = printPath(A, B, path);
    return path;
}