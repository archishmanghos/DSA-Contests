#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    void maxDiff (TreeNode *root, int maxx, int minn, int &ans) {
        ans = max (ans, max (abs (root->val - maxx), abs (root->val - minn)));
        if (root->left) {
            maxDiff (root->left, max (maxx, root->left->val), min (minn, root->left->val), ans);
        }
        if (root->right) {
            maxDiff (root->right, max (maxx, root->right->val), min (minn, root->right->val), ans);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        maxDiff (root, root->val, root->val, ans);
        return ans;
    }
};