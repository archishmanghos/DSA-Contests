#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		vector<int> degree(n, 0);
		vector<vector<int>> hash(n, vector<int>(n, -1));

		for (auto i : roads) {
			degree[i[0]]++;
			degree[i[1]]++;
			hash[i[0]][i[1]] = hash[i[1]][i[0]] = 1;
		}

		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int effectiveRank = degree[i] + degree[j];
				if (hash[i][j] != -1) effectiveRank--;
				answer = max(answer, effectiveRank);
			}
		}

		return answer;
	}
};