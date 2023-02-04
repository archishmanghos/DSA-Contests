#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int n = s1.size();
		if (s2.size() < n) return false;
		vector<int> cntS1 (26, 0);
		for (char c : s1) cntS1[c - 'a'] += 1;

		vector<int> cntS2 (26, 0);
		for (int i = 0; i < n - 1; i++) cntS2[s2[i] - 'a'] += 1;
		for (int i = n - 1; i < s2.size(); i++) {
			cntS2[s2[i] - 'a'] += 1;
			bool has = true;
			for (int j = 0; j < 26; j++) {
				has &= (cntS1[j] == cntS2[j]);
			}
			cntS2[s2[i - n + 1] - 'a'] -= 1;
			if (has) return has;
		}

		return false;
	}
};