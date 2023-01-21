#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool check (string s) {
		int num = 0, j = 1, last = -1, preLast = -1;
		while (s.size() > 0) {
			if (s.back() == '.') {
				if (num > 255) return false;
				if (last == 0 and preLast != -1) return false;
				num = 0, j = 1, last = -1, preLast = -1;
			} else {
				if (j == 1000) return false;
				preLast = last;
				last = s.back() - '0';
				num += last * j;
				j *= 10;
			}
			s.pop_back();
		}

		if (num > 255) return false;
		if (last == 0 and preLast != -1) return false;
		return true;
	}
	void helper (int idx, int dots, string x, string &s, vector<string> &ans) {
		if (idx == s.size() - 1) {
			if (dots == 0) {
				x += s[idx];
				if (check (x)) ans.push_back(x);
			}
			return;
		}

		x += s[idx];
		helper (idx + 1, dots, x, s, ans);
		if (dots > 0) {
			x += '.';
			helper (idx + 1, dots - 1, x, s, ans);
		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> answer;
		helper (0, 3, "", s, answer);
		return answer;
	}
};