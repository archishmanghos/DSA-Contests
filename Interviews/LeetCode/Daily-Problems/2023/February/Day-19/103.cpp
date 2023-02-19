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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> answer;
		if (!root) return {};
		queue<TreeNode*> q;
		q.push(root);
		int cur = 1;

		while (!q.empty()) {
			int sz = q.size();
			vector<int> temp(sz);
			for (int i = 0; i < sz; i++) {
				auto node = q.front();
				q.pop();

				if (cur) temp[i] = node->val;
				else temp[sz - i - 1] = node->val;

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}

			answer.push_back(temp);
			cur ^= 1;
		}

		return answer;
	}
};