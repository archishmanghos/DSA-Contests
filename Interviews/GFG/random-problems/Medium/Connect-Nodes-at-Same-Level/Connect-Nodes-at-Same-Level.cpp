#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node* nextRight;
};

class Solution {
public:
	void connect(Node *root) {
		queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			int sz = q.size();
			Node *preNode = NULL;
			while (sz--) {
				Node *cur = q.front();
				q.pop();

				if (preNode) preNode->nextRight = cur;
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);

				preNode = cur;
			}
			preNode->nextRight = NULL;
		}
	}
};