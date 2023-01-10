#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
};

class Solution {
public:
	int getSum (Node *node) {
		if (!node) return 0;

		int preVal = node->data;
		node->data = getSum (node->left) + getSum (node->right);
		return node->data + preVal;
	}

	void toSumTree(Node *node) {
		int totSum = getSum (node);
	}
};