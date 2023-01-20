#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void helper (int idx, vector<int> is, vector<int> &nums, vector<vector<int>> &ans) {
		if (idx == nums.size()) return;
		helper (idx + 1, is, nums, ans);
		if (is.size() == 0 or nums[idx] >= is.back()) {
			is.push_back(nums[idx]);
			if (is.size() > 1) ans.push_back(is);
			helper (idx + 1, is, nums, ans);
		}
	}
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> answer;
		helper (0, {}, nums, answer);
		sort (answer.begin(), answer.end());
		auto it = unique (answer.begin(), answer.end());
		answer.resize (distance (answer.begin(), it));
		return answer;
	}
};