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
    int sum(TreeNode* root, int& maxPath, int& minNegPath) {
        if (!root) {
            return 0;
        }

        int curNode = root->val;
        int leftPathSum = sum(root->left, maxPath, minNegPath), rightPathSum = sum(root->right, maxPath, minNegPath);
        maxPath = max(maxPath, max(curNode + leftPathSum + rightPathSum, max(leftPathSum, rightPathSum)));
        minNegPath = max(minNegPath, curNode);

        return max(0, max(curNode + leftPathSum, curNode + rightPathSum));
    }
    int maxPathSum(TreeNode* root) {
        int maxPath = 0, minNegPath = -1e9;
        int ans = sum(root, maxPath, minNegPath);
        if (minNegPath < 0) {
            return minNegPath;
        }
        return max(ans, maxPath);
    }
};