#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minOperation(string s) {
		int answer = s.size(), n = s.size();
		for (int i = 0; i < n / 2; i++) {
			string s1 = s.substr(0, i + 1);
			string s2 = s.substr(i + 1, i + 1);
			if (s1 == s2) answer = min (answer, i + 1 + 1 + (n - 2 * (i + 1)));
		}

		return answer;
	}
};