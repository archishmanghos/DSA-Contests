#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x) {
		data = x;
		next = NULL;
		bottom = NULL;
	}

};

class Solution {
public:
	Node *flatten(Node *root) {
		Node *dummy = root;
		vector<int> nodes;
		while (dummy) {
			Node *secondDummy = dummy;
			while (secondDummy) {
				nodes.emplace_back(secondDummy->data);
				secondDummy = secondDummy->bottom;
			}
			dummy = dummy->next;
		}

		sort (nodes.begin(), nodes.end());
		Node *answer = new Node(nodes[0]);
		dummy = answer;

		for (int i = 1; i < nodes.size(); i++) {
			dummy->bottom = new Node (nodes[i]);
			dummy = dummy->bottom;
		}

		return answer;
	}
};