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
    TreeNode *build(int l, int r, int &i, unordered_map<int, int> &idx, vector<int>& inorder, vector<int>& postorder) {
        if (l > r) return NULL;
        TreeNode *root = new TreeNode(postorder[i]);
        int index = idx[postorder[i--]];
        root->right = build(index + 1, r, i, idx, inorder, postorder);
        root->left = build(l, index - 1, i, idx, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> idx;
        for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
        int i = n - 1;
        return build(0, n - 1, i, idx, inorder, postorder);
    }
};