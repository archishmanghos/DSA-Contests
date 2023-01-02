#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

class Solution {
public:
	vector<int> maximumValue(Node* node) {
		vector<int> ans;
		queue<Node*> q;
		q.push(node);

		while (!q.empty()) {
			int sz = q.size(), maximum = 0;
			for (int i = 1; i <= sz; i++) {
				Node *cur = q.front();
				q.pop();

				maximum = max (maximum, cur->data);
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}

			ans.emplace_back(maximum);
		}

		return ans;
	}
};