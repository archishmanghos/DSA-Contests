#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int n = p.size();
		if (n > s.size()) return {};
		vector<int> cnt (26, 0), origCnt (26, 0);
		for (int i = 0; i < n - 1; i++) {
			cnt[s[i] - 'a'] += 1;
			origCnt[p[i] - 'a'] += 1;
		}
		origCnt[p[n - 1] - 'a'] += 1;

		vector<int> answer;
		for (int i = n - 1; i < s.size(); i++) {
			cnt[s[i] - 'a'] += 1;
			bool ok = true;
			for (int j = 0; j < 26; j++) {
				ok &= cnt[j] == origCnt[j];
			}

			cnt[s[i - n + 1] - 'a'] -= 1;
			if (ok) answer.push_back(i - n + 1);
		}

		return answer;
	}
};