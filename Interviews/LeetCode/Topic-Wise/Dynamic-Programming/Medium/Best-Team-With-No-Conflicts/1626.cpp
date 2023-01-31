#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int n = scores.size();
		vector<vector<int>> v (n);
		for (int i = 0; i < scores.size(); i++) v[i] = {ages[i], scores[i]};

		sort(v.begin(), v.end());
		int cache[1000][1002];
		memset (cache, -1, sizeof (cache));

		auto dp = [&](int idx, int minScoreIdx, auto && dp) {
			if (idx == scores.size()) return 0;
			int &answer = cache[idx][minScoreIdx];
			if (answer != -1) return answer;

			answer = dp (idx + 1, minScoreIdx, dp);
			if (minScoreIdx == 0 or v[idx][1] >= v[minScoreIdx - 1][1]) {
				answer = max (answer, dp (idx + 1, idx + 1, dp) + v[idx][1]);
			}

			return answer;
		};

		return dp (0, 0, dp);
	}
};