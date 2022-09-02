vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        long sum = 0;
        for (int i = 0; i < sz; i++) {
            TreeNode* curNode = q.front();
            q.pop();
            sum += curNode->val;
            if (curNode->left) q.push(curNode->left);
            if (curNode->right) q.push(curNode->right);
        }
        double avg = (sum * 1.0) / sz;
        ans.push_back(avg);
    }

    return ans;
}