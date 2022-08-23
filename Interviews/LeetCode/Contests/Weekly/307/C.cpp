void dfs(TreeNode* root, int start, map<TreeNode*, TreeNode*> &parent, queue<TreeNode*> &q) {
    if (!root) return;
    if (root->val == start) q.push(root);
    if (root->left) parent[root->left] = root;
    if (root->right) parent[root->right] = root;
    dfs(root->left, start, parent, q);
    dfs(root->right, start, parent, q);
}
int amountOfTime(TreeNode* root, int start) {
    map<TreeNode*, TreeNode*> parent;
    int ans = -1;
    queue<TreeNode*> q;
    dfs(root, start, parent, q);
    set<TreeNode*> visited;

    while (!q.empty()) {
        bool atleastOne = false;
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            TreeNode* curNode = q.front();
            q.pop();
            if (visited.find(curNode) != visited.end()) continue;
            atleastOne = true;
            visited.insert(curNode);

            if (curNode->left) q.push(curNode->left);
            if (curNode->right) q.push(curNode->right);
            if (parent.find(curNode) != parent.end()) q.push(parent[curNode]);
        }
        ans += atleastOne;
    }

    return ans;
}