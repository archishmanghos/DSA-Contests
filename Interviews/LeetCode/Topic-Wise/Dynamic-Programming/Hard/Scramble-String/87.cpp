#include <bits/stdc++.h>
using namespace std;

class Solution {
	int cache[32][32][32];
public:
	int dp (int l_s1, int r_s1, int l_s2, string &s1, string &s2) {
		int n = r_s1 - l_s1 + 1;
		if (n == 1) return s1[l_s1] == s2[l_s2];

		int &answer = cache[l_s1][r_s1][l_s2];
		if (answer != -1) return answer;

		answer = 0;
		for (int i = 0; i + 1 < n; i++) {
			answer |= dp (l_s1, l_s1 + i, l_s2, s1, s2) and dp (l_s1 + i + 1, r_s1, l_s2 + i + 1, s1, s2);
			answer |= dp (l_s1 + i + 1, r_s1, l_s2, s1, s2) and dp (l_s1, l_s1 + i, l_s2 + n - (i + 1), s1, s2);
			if (answer) break;
		}

		return answer;
	}
	bool isScramble(string s1, string s2) {
		memset(cache, -1, sizeof(cache));
		return dp (0, s1.size() - 1, 0, s1, s2);
	}
};