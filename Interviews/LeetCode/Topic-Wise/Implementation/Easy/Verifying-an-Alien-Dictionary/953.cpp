#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		vector<int> degree (26, 0);
		for (int i = 0; i < 26; i++) degree[order[i] - 'a'] = i;

		auto checkSorted = [&](int i, int j) {
			int ii = 0, jj = 0;
			while (ii < words[i].size() and jj < words[j].size()) {
				if (degree[words[i][ii] - 'a'] != degree[words[j][jj] - 'a']) {
					return degree[words[i][ii] - 'a'] < degree[words[j][jj] - 'a'];
				}
				ii += 1, jj += 1;
			}

			return ii == words[i].size();
		};

		for (int i = 1; i < words.size(); i++) if (!checkSorted (i - 1, i)) return false;

		return true;
	}
};