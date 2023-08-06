#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		vector<int> values;
		while (head->next) {
			int a = head->val, b = head->next->val;
			values.push_back(__gcd(a, b));
		}

		if (values.size() == 0) return head;

		int i = 0l;
		ListNode *answer = head;
		while (head->next) {
			ListNode *temp = head->next;
			head->next = new ListNode(values[i++]);
			head = head->next;
			head->next = temp;
			head = head->next;
		}

		return answer;
	}
};