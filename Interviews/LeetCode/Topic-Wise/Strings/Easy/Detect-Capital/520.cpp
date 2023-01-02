#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		bool allSmall = true, allLarge = true, capital = true;

		auto getDegree = [](char c) {
			if (c >= 'A' and c <= 'Z') return 1;
			if (c >= 'a' and c <= 'z') return -1;
			return 0;
		};

		for (int i = 0; i < word.size(); i++) {
			allSmall &= getDegree (word[i]) == -1;
			allLarge &= getDegree (word[i]) == 1;
			capital &= ((i == 0 and getDegree (word[i]) == 1) or (i > 0 and getDegree (word[i]) == -1));
		}

		return allSmall or allLarge or capital;
	}
};