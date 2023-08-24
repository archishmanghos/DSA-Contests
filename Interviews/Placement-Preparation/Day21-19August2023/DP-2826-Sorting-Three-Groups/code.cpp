#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> cache(n, vector<int>(5, -1));
		function<int(int, int)> dp = [&](int idx, int pre) {
			if (idx == n) return 0;
			if (cache[idx][pre] != -1) return cache[idx][pre];

			int answer = 1e9, start = (idx == 0 ? 1 : pre);
			for (int i = start; i <= 3; i++) {
				answer = min(answer, dp(idx + 1, i) + (i != nums[idx]));
			}

			return cache[idx][pre] = answer;
		};

		return dp(0, 0);
	}
};