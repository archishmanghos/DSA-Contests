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
	void dfs(TreeNode* root, int sum, int lvl, unordered_map<int, int> &level) {
		if (!root) return;

		int originalSum = 0;
		if (root->left) originalSum += root->left->val;
		if (root->right) originalSum += root->right->val;

		root->val = level[lvl] - sum;
		dfs(root->left, originalSum, lvl + 1, level);
		dfs(root->right, originalSum, lvl + 1, level);
	}

	TreeNode* replaceValueInTree(TreeNode* root) {
		unordered_map<int, int> level;
		queue<TreeNode*> q;
		q.push(root);
		int lvl = 0;

		while (!q.empty()) {
			int sz = q.size(), sum = 0;
			lvl++;
			for (int i = 1; i <= sz; i++) {
				auto node = q.front(); q.pop();
				sum += node->val;
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			level[lvl] = sum;
		}

		dfs(root, root->val, 1, level);
		return root;
	}
};