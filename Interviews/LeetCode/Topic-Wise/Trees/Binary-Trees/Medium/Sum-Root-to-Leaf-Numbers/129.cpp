#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum (TreeNode* root, int numberTillNow) {
        if (!root->left and !root->right) return (numberTillNow * 10 + root->val);
        int leftSum = (root->left ? sum(root->left, numberTillNow * 10 + root->val) : 0);
        int rightSum = (root->right ? sum(root->right, numberTillNow * 10 + root->val) : 0);
        return  leftSum + rightSum;
    }
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
};