int widthOfBinaryTree(TreeNode *root) {
    map < TreeNode * , long long > index;
    queue < TreeNode * > q;
    q.push(root);
    index[root] = 0;
    int ans = 1;

    while (!q.empty()) {
        int sz = q.size();
        vector<int> v;
        long long minIndex = -1;
        for (int i = 1; i <= sz; i++) {
            TreeNode *curNode = q.front();
            q.pop();

            if (curNode->left) {
                if (minIndex == -1) {
                    minIndex = 2 * index[curNode];
                }
                index[curNode->left] = 2 * index[curNode] - minIndex;
                q.push(curNode->left);
                if (v.size() <= 1) {
                    v.push_back(index[curNode->left]);
                } else {
                    if (v.back() < index[curNode->left]) {
                        v.pop_back();
                        v.push_back(index[curNode->left]);
                    }
                }

            }
            if (curNode->right) {
                if (minIndex == -1) {
                    minIndex = 2 * index[curNode] + 1;
                }
                index[curNode->right] = 2 * index[curNode] + 1 - minIndex;
                q.push(curNode->right);
                if (v.size() <= 1) {
                    v.push_back(index[curNode->right]);
                } else {
                    if (v.back() < index[curNode->right]) {
                        v.pop_back();
                        v.push_back(index[curNode->right]);
                    }
                }
            }
        }

        if (v.size() > 0) {
            ans = max(ans, (v.back() - v[0] + 1));
        }
    }

    return ans;
}