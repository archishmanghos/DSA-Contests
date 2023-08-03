#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> answer;
		unordered_map<char, vector<char>> ump;
		ump['2'] = {'a', 'b', 'c'};
		ump['3'] = {'d', 'e', 'f'};
		ump['4'] = {'g', 'h', 'i'};
		ump['5'] = {'j', 'k', 'l'};
		ump['6'] = {'m', 'n', 'o'};
		ump['7'] = {'p', 'q', 'r', 's'};
		ump['8'] = {'t', 'u', 'v'};
		ump['9'] = {'w', 'x', 'y', 'z'};

		function<void(int, string)> f = [&](int idx, string comb) {
			if (idx == digits.size()) {
				if (comb.size()) answer.push_back(comb);
				return;
			}

			for (char i : ump[digits[idx]]) {
				comb += i;
				f (idx + 1, comb);
				comb.pop_back();
			}
		};

		f (0, "");
		return answer;
	}
};