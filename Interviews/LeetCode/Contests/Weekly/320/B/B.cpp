class Solution {
   public:
    void inorder(TreeNode* root, vector<int>& in) {
        if (!root)
            return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> in;
        inorder(root, in);
        int q = queries.size();
        vector<vector<int>> ans(q);
        for (int i = 0; i < q; i++) {
            vector<int> v = {-1, -1};
            auto it = lower_bound(in.begin(), in.end(), queries[i]);
            if (it != in.end()) {
                int lg = it - in.begin();
                v[1] = in[lg];
                if (in[lg] == queries[i]) {
                    v[0] = in[lg];
                } else {
                    if (it != in.begin()) {
                        int sm = it - in.begin();
                        v[0] = in[sm - 1];
                    }
                }
            } else {
                if (it != in.begin()) {
                    int sm = it - in.begin();
                    v[0] = in[sm - 1];
                }
            }

            ans[i] = v;
        }

        return ans;
    }
};