#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int closetTarget(vector<string>& words, string target, int startIndex) {
		int ans = 1e9, n = words.size();
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == target) {
				if (i == startIndex) return 0;
				if (i < startIndex) ans = min(ans, min(startIndex - i, (n - startIndex - 1) + (i + 1)));
				if (i > startIndex) ans = min(ans, min(i - startIndex, startIndex + (n - i)));
			}
		}

		return (ans == (int)1e9 ? -1 : ans);
	}
};