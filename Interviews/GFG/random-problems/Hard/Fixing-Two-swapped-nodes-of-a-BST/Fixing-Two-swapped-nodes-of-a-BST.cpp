#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

class Solution {
public:
	void inorder (struct Node* root, struct Node* &prev, pair<pair<struct Node*, struct Node*>, Node*> &swapped) {
		if (!root) return;

		inorder (root->left, prev, swapped);
		if (prev) {
			if (root->data < prev->data) {
				if (swapped.first.first) {
					swapped.second = root;
				}
				else {
					swapped.first.first = prev;
					swapped.first.second = root;
				}
			}
		}
		prev = root;
		inorder (root->right, prev, swapped);
	}
	struct Node *correctBST(struct Node *root) {
		pair<pair<struct Node*, struct Node*>, Node*> swapped;
		swapped = {{NULL, NULL}, NULL};
		struct Node* prev = NULL;
		inorder (root, prev, swapped);
		if (swapped.second) {
			swap (swapped.first.first->data, swapped.second->data);
		} else {
			swap (swapped.first.first->data, swapped.first.second->data);
		}
		return root;
	}
};