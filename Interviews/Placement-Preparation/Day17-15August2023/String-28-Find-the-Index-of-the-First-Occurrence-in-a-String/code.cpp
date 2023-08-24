#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		string s = needle + '$' + haystack;
		int n = s.size(), l = 0, r = 0;
		vector<int> z(n, 0);

		for (int i = 1; i < n; i++) {
			if (i <= r) z[i] = min(z[i - l], r - i + 1);
			while (i + z[i] < n and s[i + z[i]] == s[z[i]]) z[i]++;
			if (i > needle.size() and z[i] == (int)needle.size()) return (i - (int)needle.size() - 1);
			if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
		}

		return -1;
	}
};