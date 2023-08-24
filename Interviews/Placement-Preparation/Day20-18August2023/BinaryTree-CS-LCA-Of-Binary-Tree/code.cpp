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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y) {
	if (!root) return -1;
	if (root->data == x or root->data == y) return root->data;
	int leftTree = lowestCommonAncestor(root->left, x, y);
	int rightTree = lowestCommonAncestor(root->right, x, y);
	if (leftTree != -1 and rightTree != -1) return root->data;
	if (leftTree != -1) return leftTree;
	if (rightTree != -1) return rightTree;
	return -1;
}