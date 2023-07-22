#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long dp(int idx, int curPar, vector<int> &nums, int x, vector<vector<long long>> &cache) {
		if (idx == nums.size()) return 0;
		long long &answer = cache[idx][curPar];
		if (answer != -1) return answer;

		answer = 0;
		long long par = nums[idx] % 2;
		if (par == curPar) answer = dp(idx + 1, par, nums, x, cache) + nums[idx];
		else answer = max(dp(idx + 1, curPar, nums, x, cache), dp(idx + 1, par, nums, x, cache) + nums[idx] - x);
		return answer;
	}
	long long maxScore(vector<int>& nums, int x) {
		vector<vector<long long>> cache(nums.size(), vector<long long>(2, -1));
		return dp(0, nums[0] % 2, nums, x, cache);
	}
};