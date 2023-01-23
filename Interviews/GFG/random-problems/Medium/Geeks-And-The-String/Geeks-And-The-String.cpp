#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removePair(string s) {
		string answer;
		for (char c : s) {
			bool noPop = true;
			while (answer.size() and answer.back() == c) {
				answer.pop_back();
				noPop = false;
			}

			if (noPop) answer.push_back(c);
		}

		return (answer.size() == 0 ? "-1" : answer);
	}
};