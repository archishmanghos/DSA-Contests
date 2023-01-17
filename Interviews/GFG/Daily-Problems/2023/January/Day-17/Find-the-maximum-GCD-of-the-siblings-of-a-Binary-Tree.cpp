#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

class Solution {
public:
	void getAnswer (Node *root, int &gcd, int &ans) {
		if (!root) return;

		if (root->left and root->right) {
			int curGcd = __gcd (root->left->data, root->right->data);
			if (curGcd >= gcd) {
				if (curGcd == gcd) ans = max (ans, root->data);
				else ans = root->data;
				gcd = curGcd;
			}
		}

		getAnswer (root->left, gcd, ans);
		getAnswer (root->right, gcd, ans);
	}
	int maxGCD( Node* root) {
		int answer = 0, gcd = -1;
		getAnswer (root, gcd, answer);
		return answer;
	}
};