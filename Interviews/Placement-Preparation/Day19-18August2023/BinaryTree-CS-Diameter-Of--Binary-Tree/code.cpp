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

int diameter(TreeNode<int> *root, int &answer) {
	if (!root) return 0;
	int leftHeight = diameter(root->left, answer);
	int rightHeight = diameter(root->right, answer);
	answer = max (answer, leftHeight + rightHeight);
	return 1 + max (leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode<int> *root) {
	int answer = 0;
	int h = diameter(root, answer);
	return answer;
}