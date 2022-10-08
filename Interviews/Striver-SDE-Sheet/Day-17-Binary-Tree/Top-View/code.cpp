class Solution {
public:
    vector<int> topView(Node *root) {
        map<int, int> level;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            Node* curNode = q.front().first;
            int lvl = q.front().second;
            q.pop();

            if (level.find(lvl) == level.end()) level[lvl] = curNode->data;
            if (curNode->left) q.push({curNode->left, lvl - 1});
            if (curNode->right) q.push({curNode->right, lvl + 1});
        }

        vector<int> ans;
        for (auto i : level) {
            ans.push_back(i.second);
        }

        return ans;
    }
};