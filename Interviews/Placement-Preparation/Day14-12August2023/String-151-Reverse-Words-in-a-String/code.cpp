#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		string answer = "", text = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (text.size()) answer = text + ' ' + answer;
				text = "";
			} else {
				text += s[i];
			}
		}

		if (text.size()) answer = text + ' ' + answer;
		answer.pop_back();
		return answer;
	}
};