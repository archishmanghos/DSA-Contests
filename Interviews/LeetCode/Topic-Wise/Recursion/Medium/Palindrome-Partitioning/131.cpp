#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void helper (int idx, vector<string> t, string &s, vector<vector<string>> &ans) {
		if (idx == s.size()) {
			ans.push_back(t);
			return;
		}

		auto isPal = [&](int l, int r) {
			while (l < r) if (s[l++] != s[r--]) return false;
			return true;
		};

		string x = "";
		for (int i = idx; i < s.size(); i++) {
			x += s[i];
			if (isPal (idx, i)) {
				t.push_back(x);
				helper (i + 1, t, s, ans);
				t.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> answer;
		helper (0, {}, s, answer);
		return answer;
	}
};