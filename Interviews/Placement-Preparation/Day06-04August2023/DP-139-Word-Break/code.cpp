#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_map<string, bool> ump;
		int cache[300][300];
		memset (cache, -1, sizeof(cache));

		for (string s : wordDict) ump[s] = 1;

		function<int(int, int)> dp = [&](int startIdx, int idx) {
			if (idx == s.size() - 1) return ump.find(s.substr(startIdx)) != ump.end() ? 1 : 0;
			int &answer = cache[startIdx][idx];
			if (answer != -1) return answer;

			answer = dp (startIdx, idx + 1);
			if (ump.find(s.substr(startIdx, idx - startIdx + 1)) != ump.end()) {
				answer |= dp (idx + 1, idx + 1);
			}

			return answer;
		};

		return dp (0, 0);
	}
};