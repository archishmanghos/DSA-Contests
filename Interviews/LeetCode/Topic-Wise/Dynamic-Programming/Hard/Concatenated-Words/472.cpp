#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		unordered_map<string, bool> ump;
		for (string s : words) ump[s] = true;
		int cache[35][4];

		auto dp = [&](int idx, int minCnt, int word, auto && dp) {
			if (idx == words[word].size()) return (minCnt == 2 ? 1 : 0);
			if (cache[idx][minCnt] != -1) return cache[idx][minCnt];

			string cur = "";
			for (int i = idx; i < words[word].size(); i++) {
				cur += words[word][i];
				if (ump.find(cur) != ump.end()) {
					if (dp (i + 1, min (minCnt + 1, 2), word, dp)) return cache[idx][minCnt] = 1;
				}
			}

			return cache[idx][minCnt] = 0;
		};

		vector<string> answer;
		for (int i = 0; i < words.size(); i++) {
			memset (cache, -1, sizeof(cache));
			if (dp (0, 0, i, dp)) answer.push_back(words[i]);
		}

		return answer;
	}
};