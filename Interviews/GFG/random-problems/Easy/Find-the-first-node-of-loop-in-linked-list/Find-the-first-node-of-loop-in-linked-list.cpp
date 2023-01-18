#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class Solution {
public:
	int findFirstNode(Node* head) {
		Node *temp = head, *slow = head, *fast = head;
		bool start = true;
		while (start or slow != fast) {
			if (!slow) return -1;
			slow = slow->next;
			if (!fast or !fast->next) return -1;
			fast = fast->next->next;
			start = false;
		}

		while (slow != temp) {
			slow = slow->next;
			temp = temp->next;
		}

		return slow->data;
	}
};