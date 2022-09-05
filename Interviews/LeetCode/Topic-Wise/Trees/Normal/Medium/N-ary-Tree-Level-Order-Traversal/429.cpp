vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;

    while (!q.empty()) {
        int sz = q.size();
        vector<int> temp(sz);
        for (int i = 1; i <= sz; i++) {
            Node* curNode = q.front();
            q.pop();
            temp[i - 1] = curNode->val;
            for (Node* child : curNode->children) {
                q.push(child);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}