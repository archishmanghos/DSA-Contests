#include<bits/stdc++.h>

int minLength(int n, string &s) {
	int answer = n;
	for (char c = 'z'; c > 'a'; c--) {
		string x = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == c and x.size() and x.back() == (c - 1)) {
				answer -= 1;
				continue;
			}
			if (s[i] == c - 1) {
				while (x.size() and x.back() == c) {
					x.pop_back();
					answer -= 1;
				}
			}
			x.push_back(s[i]);
		}
		s = x;
	}

	return answer;
}