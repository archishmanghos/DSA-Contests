#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool helper (Node *root, int &ans) {
		if (!root) return true;

		int leftTree = root->left ? root->left->data : root->data;
		int rightTree = root->right ? root->right->data : root->data;

		bool leftSingle = helper (root->left, ans);
		bool rightSingle = helper (root->right, ans);

		if (!leftSingle or !rightSingle) return false;
		if (root->data != leftTree or root->data != rightTree) return false;

		ans += 1;
		return true;
	}

	int singlevalued(Node *root) {
		int ans = 0;
		bool help = helper (root, ans);
		return ans;
	}
};