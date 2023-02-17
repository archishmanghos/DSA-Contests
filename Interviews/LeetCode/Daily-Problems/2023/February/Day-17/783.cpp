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
	vector<TreeNode*> st;
	void push (TreeNode* root) {
		while (root) {
			st.push_back(root);
			root = root->left;
		}
	}

	int getNext () {
		if (!st.size()) return -1;
		TreeNode *node = st.back();
		st.pop_back();
		int answer = node->val;

		push(node->right);
		return answer;
	}

	int minDiffInBST(TreeNode* root) {
		push (root);
		int pre = getNext(), cur = getNext(), answer = int(1e9);
		while (cur != -1) {
			answer = min (answer, cur - pre);
			pre = cur;
			cur = getNext();
		}

		return answer;
	}
};