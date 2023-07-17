#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestValidSubstring(string word, vector<string>& forbidden) {
		unordered_map<string, int> ump;
		for (string s : forbidden) ump[s] = 1;
		int i = 0, j = 0, answer = 0;
		while (j < word.size()) {
			auto f = [&]() {
				int x = (j - i);
				for (int k = j - min(x, 9); k <= j; k++) {
					if (ump.find(word.substr(k, j - k + 1)) != ump.end()) return true;
				}
				return false;
			};

			if (f()) i += 1;
			else {
				answer = max(answer, j - i + 1);
				j += 1;
			}
		}

		return answer;
	}
};