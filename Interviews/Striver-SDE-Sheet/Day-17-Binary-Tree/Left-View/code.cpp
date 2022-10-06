vector<int> leftView(Node *root) {
    if (!root) return {};
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            Node* curNode = q.front();
            q.pop();
            if (i == 1) ans.push_back(curNode->data);
            if (curNode->left) q.push(curNode->left);
            if (curNode->right) q.push(curNode->right);
        }
    }

    return ans;
}