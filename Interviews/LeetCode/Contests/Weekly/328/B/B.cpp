#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
		vector<vector<int>> answer(n, vector<int>(n, 0));
		for (auto query : queries) {
			int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3];
			answer[r1][c1] += 1;
			if (r2 + 1 < n) answer[r2 + 1][c1] -= 1;
			if (c2 + 1 < n) answer[r1][c2 + 1] -= 1;
			if (r2 + 1 < n and c2 + 1 < n) answer[r2 + 1][c2 + 1] += 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i - 1 >= 0) answer[i][j] += answer[i - 1][j];
				if (j - 1 >= 0) answer[i][j] += answer[i][j - 1];
				if (i - 1 >= 0 and j - 1 >= 0) answer[i][j] -= answer[i - 1][j - 1];
			}
		}

		return answer;
	}
};