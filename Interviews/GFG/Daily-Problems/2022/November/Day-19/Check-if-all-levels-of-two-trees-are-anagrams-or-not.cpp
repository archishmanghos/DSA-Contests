class Solution {
    public:
    vector<set<int>> getLevels (Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<set<int>> v;
        
        while (!q.empty()) {
            int sz = q.size();
            set<int> cur;
            for (int i = 1; i <= sz; i++) {
                Node* curNode = q.front();
                q.pop();
                cur.insert(curNode->data);
                if (curNode->left) {
                    q.push(curNode->left);
                }
                if (curNode->right) {
                    q.push(curNode->right);
                }
            }
            v.push_back(cur);
        }
        
        return v;
    }
    bool areAnagrams(Node *root1, Node *root2) {
        vector<set<int>> a1 = getLevels (root1);
        vector<set<int>> a2 = getLevels (root2);
        if (a1.size() != a2.size()) return false;
        for (int i = 0; i < a1.size(); i++) {
            if (a1[i] != a2[i]) return false;
        }
        
        return true;
    }
};