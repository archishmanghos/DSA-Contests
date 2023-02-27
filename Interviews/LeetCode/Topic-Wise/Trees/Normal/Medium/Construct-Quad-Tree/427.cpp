#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {
		val = false;
		isLeaf = false;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};


class Solution {
public:
	Node* quadTree (int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
		bool same = true;
		int val = grid[r1][c1];
		for (int i = r1; i <= r2; i++) {
			for (int j = c1; j <= c2; j++) {
				same &= grid[i][j] == val;
			}
		}

		Node *root = new Node();
		root->val = val;
		if (same) {
			root->isLeaf = true;
			return root;
		}

		root->isLeaf = false;
		root->topLeft = quadTree (r1, c1, ((r1 + r2) >> 1), ((c1 + c2) >> 1), grid);
		root->topRight = quadTree (r1, ((c1 + c2 + 1) >> 1), ((r1 + r2) >> 1), c2, grid);
		root->bottomLeft = quadTree (((r1 + r2 + 1) >> 1), c1, r2, ((c1 + c2) >> 1), grid);
		root->bottomRight = quadTree (((r1 + r2 + 1) >> 1), ((c1 + c2 + 1) >> 1), r2, c2, grid);

		return root;
	}
	Node* construct(vector<vector<int>>& grid) {
		return quadTree (0, 0, grid.size() - 1, grid[0].size() - 1, grid);
	}
};