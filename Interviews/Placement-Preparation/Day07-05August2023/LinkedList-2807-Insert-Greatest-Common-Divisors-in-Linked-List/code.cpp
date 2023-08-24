#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		vector<int> values;
		ListNode *temp = head;
		while (head->next) {
			int a = head->val, b = head->next->val;
			values.push_back(__gcd(a, b));
			head = head->next;
		}

		head = temp;
		if (values.size() == 0) return head;


		int i = 0;
		ListNode *answer = head;
		while (head and head->next) {
			ListNode *temp = head->next;
			head->next = new ListNode(values[i++]);
			head = head->next;
			head->next = temp;
			head = head->next;
		}

		return answer;
	}
};