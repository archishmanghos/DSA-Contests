#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;
		bool equal = false;
		while (!equal and slow and fast and fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) equal = true;
		}

		if (!equal) return NULL;
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}
};
