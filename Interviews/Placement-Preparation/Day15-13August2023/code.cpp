#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *links[26];
	int count[26];
	bool hasNode (char c) {
		return links[c - 'a'] != NULL;
	}
	void createNode(char c) {
		links[c - 'a'] = new Node();
	}
	Node *nextNode (char c) {
		return links[c - 'a'];
	}
	void setCount(char c) {
		count[c - 'a']++;
	}
	int getCount(char c) {
		return count[c - 'a'];
	}
};
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		Node *root = new Node();
		for (string s : strs) {
			Node *temp = root;
			for (char c : s) {

				if (!temp->hasNode(c)) temp->createNode(c);
				temp->setCount(c);
				temp = temp->nextNode(c);

			}
		}

		Node *temp = root;

		string answer = "";
		for (char c : strs[0]) {
			if (temp->getCount(c) == strs.size()) {
				answer += c;
				temp = temp->nextNode(c);
			} else break;
		}

		return answer;
	}
};