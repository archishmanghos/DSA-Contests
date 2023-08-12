#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		string s1 = "$";
		for (int i = 0; i < s.size(); i++) {
			s1 += '#';
			s1 += s[i];
		}
		s1 += "#^";
		int n = s1.size(), p[n + 2], l = 1, r = 1;
		memset(p, 0, sizeof(p));
		for (int i = 1; i < n; i++) {
			p[i] = max (0, min(p[l + r - i], r - i));
			while (s1[i - p[i]] == s1[i + p[i]]) p[i]++;
			if (i + p[i] > r) l = i - p[i], r = i + p[i];
		}

		int maxLen = *max_element (p + 1, p + n + 1);
		for (int i = 1; i < n; i++) {
			if (p[i] == maxLen) {
				string answer = "";
				if (s1[i] != '#') answer += s1[i];
				int k = p[i] - 2, j = i - (s1[i] == '#' ? 1 : 2);
				while (k > 0) {
					answer = s1[j] + answer + s1[j];
					j -= 2;
					k -= 2;
				}

				return answer;
			}
		}

		return "-1";
	}
};