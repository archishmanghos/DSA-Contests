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
    int totSum(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return root->val + totSum(root->left) + totSum(root->right);
    }

    long maxProd(TreeNode* root, long totalSum, long& ans) {
        if (!root) {
            return 0;
        }

        long leftSum = maxProd(root->left, totalSum, ans);
        long rightSum = maxProd(root->right, totalSum, ans);
        ans = max(ans, max((totalSum - leftSum) * leftSum, (totalSum - rightSum) * rightSum));
        return root->val + leftSum + rightSum;
    }

    int maxProduct(TreeNode* root) {
        long totalSum = totSum(root), ans = 0;
        long prod = maxProd(root, totalSum, ans);
        return int(ans % int(1e9 + 7));
    }
};