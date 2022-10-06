class Solution {
public:
    vector <int> bottomView(Node *root) {
        map<int, int> indices;
        vector<int> ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            Node* curNode = q.front().first;
            int level = q.front().second;
            q.pop();
            indices[level] = curNode->data;
            if (curNode->left) q.push({curNode->left, level - 1});
            if (curNode->right) q.push({curNode->right, level + 1});
        }

        for (auto key : indices) {
            ans.push_back(key.second);
        }

        return ans;
    }
};