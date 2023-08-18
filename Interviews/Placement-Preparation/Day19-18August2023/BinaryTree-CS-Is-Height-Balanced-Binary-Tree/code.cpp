#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
	T val;
	TreeNode<T> *left;
	TreeNode<T> *right;

	TreeNode(T val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

int height(TreeNode<int> *root) {
	if (!root) return 0;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if (leftHeight == -1 or rightHeight == -1 or abs(leftHeight - rightHeight) > 1) return -1;
	return 1 + max (leftHeight, rightHeight);
}
bool isBalancedBT(TreeNode<int>* root) {
	int h = height(root);
	return h != -1;
}