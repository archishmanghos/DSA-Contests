void assign(TreeNode* root, int row, int col, int &minCol, int &maxCol, map<pair<int, int>, multiset<int>> &mp) {
    if (!root) return;
    minCol = min(col, minCol);
    maxCol = max(col, maxCol);
    mp[ {row, col}].insert(root->val);
    assign(root->left, row + 1, col - 1, minCol, maxCol, mp);
    assign(root->right, row + 1, col + 1, minCol, maxCol, mp);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<pair<int, int>, multiset<int>> mp;
    int minCol = 0, maxCol = 0;
    assign(root, 0, 0, minCol, maxCol, mp);
    int add = abs(minCol);
    vector<vector<int>> ans(maxCol - minCol + 1);
    for (auto it : mp) {
        int row = it.first.first, col = it.first.second;
        for (int j : it.second) {
            ans[col + add].push_back(j);
        }
    }

    return ans;
}