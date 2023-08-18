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
		if (!root) return {};
		vector<vector<int>> answer;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int sz = q.size();
			vector<int> temp(sz);
			bool reverse = ((int)answer.size() & 1);
			for (int i = 0; i < sz; i++) {
				TreeNode *it = q.front(); q.pop();
				if (reverse) temp[sz - i - 1] = it->val;
				else temp[i] = it->val;

				if (it->left) q.push(it->left);
				if (it->right) q.push(it->right);
			}
			answer.push_back(temp);
		}

		return answer;
	}
};