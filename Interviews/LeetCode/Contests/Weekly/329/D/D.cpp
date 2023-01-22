#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int64_t cache[1005];
	int64_t dp(int idx, int k, vector<int> &nums) {
		if (idx == nums.size()) return 0;

		int64_t &answer = cache[idx];
		if (answer != -1) return answer;

		answer = 1e15;
		int64_t notDistinct = 0;
		vector<int64_t> freq(1005, 0);
		for (int i = idx; i < nums.size(); i++) {
			freq[nums[i]] += 1;
			if (freq[nums[i]] > 1) {
				if (freq[nums[i]] == 2) notDistinct += 2;
				else notDistinct += 1;
			}

			answer = min(answer, dp(i + 1, k, nums) + (notDistinct + k));
		}

		return answer;
	}
	int minCost(vector<int>& nums, int k) {
		memset(cache, -1, sizeof(cache));
		return dp(0, k, nums);
	}
};