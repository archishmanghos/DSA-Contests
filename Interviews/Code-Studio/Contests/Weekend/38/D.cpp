#include <bits/stdc++.h>

string lexicographicallyMinimum(int n, string s) {
	string u = "", v = "";
	char minC = 'z';
	for (char c : s) minC = min(minC, c);
	int cntC = 0;
	for (char c : s) cntC += c == minC;
	vector<int> cnt(26, 0);
	for (char c : s) cnt[c - 'a'] += 1;
	reverse(s.begin(), s.end());
	bool flag = true;

	while (s.size() > 0) {
		if (flag) {
			if (u.size() > 0 and u.back() == minC) {
				v.push_back(u.back());
				u.pop_back();
				cntC -= 1;
				if (cntC == 0) flag = false;
			}
		}

		if (!flag) {
			while (u.size() > 0 and u.back() < s.back()) {
				bool ok = true;
				for (char i = u.back() - 1; i >= 'a'; i--) {
					if (cnt[i - 'a'] > 0) {
						ok = false;
						break;
					}
				}

				if (ok) {
					v.push_back(u.back());
					u.pop_back();
				} else break;
			}
		}
		u.push_back(s.back());
		cnt[s.back() - 'a'] -= 1;
		s.pop_back();
	}

	while (u.size() > 0) {
		v.push_back(u.back());
		u.pop_back();
	}
	return v;
}
