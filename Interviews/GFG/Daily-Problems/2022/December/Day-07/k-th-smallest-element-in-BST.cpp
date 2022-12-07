#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
   public:
    void inorder(Node* root, int& k, int& ans) {
        if (!root or ans != -1)
            return;
        inorder(root->left, k, ans);
        k -= 1;
        if (k == 0) {
            ans = root->data;
            return;
        }
        inorder(root->right, k, ans);
    }
    int KthSmallestElement(Node* root, int K) {
        int ans = -1;
        inorder(root, K, ans);
        return ans;
    }
};