TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }
    vector<TreeNode*> nodesAtDepth;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            TreeNode* curNode = q.front();
            q.pop();
            if (depth - 1 == 1) nodesAtDepth.push_back(curNode);
            if (curNode->left) q.push(curNode->left);
            if (curNode->right) q.push(curNode->right);
        }
        if (depth - 1 == 1) break;
        depth -= 1;
    }

    for (TreeNode* node : nodesAtDepth) {
        TreeNode *leftSub = node->left, *rightSub = node->right;
        node->left = new TreeNode(val);
        node->right = new TreeNode(val);
        node->left->left = leftSub;
        node->right->right = rightSub;
    }

    return root;
}