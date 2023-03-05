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
	long long kthLargestLevelSum(TreeNode* root, int k) {
		queue<TreeNode*> q;
		q.push(root);

		priority_queue<long long, vector<long long>, greater<long long>> pq;
		while (!q.empty()) {
			int sz = q.size();
			long long sum = 0;
			while (sz--) {
				auto node = q.front();
				q.pop();

				sum += node->val;
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			pq.push(sum);
			if (pq.size() > k) pq.pop();
		}

		return (pq.size() < k ? -1 : pq.top());
	}
};