#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int heightOfBinaryTree(TreeNode<int> *root) {
    if (!root) return 0;
    return 1 + max (heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
}