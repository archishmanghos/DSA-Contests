#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findColumnWidth(vector<vector<int>>& grid) {
		auto getLength = [](int x) {
			int answer = (x < 0 ? 1 : 0);
			if (x == 0) return answer + 1;
			x = abs(x);
			while (x > 0) {
				x /= 10;
				answer++;
			}

			return answer;
		};

		vector<int> answer(grid[0].size(), 0);
		for (int i = 0; i < grid[0].size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				answer[i] = max(answer[i], getLength(grid[j][i]));
			}
		}

		return answer;
	}
};