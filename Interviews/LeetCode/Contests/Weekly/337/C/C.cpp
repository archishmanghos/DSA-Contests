#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int helper(int idx, vector<int> &canttake, int n, vector<int> &nums, int k) {
		if (idx == nums.size()) return 1;
		int answer = helper(idx + 1, canttake, n, nums, k);
		if (!canttake[nums[idx]]) {
			canttake[nums[idx] + k]++;
			if (nums[idx] - k > 0) canttake[nums[idx] - k]++;
			answer += helper(idx + 1, canttake, n, nums, k);
			canttake[nums[idx] + k]--;
			if (nums[idx] - k > 0) canttake[nums[idx] - k]--;
		}

		return answer;
	}
	int beautifulSubsets(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> canttake(2005, 0);
		return helper(0, canttake, n, nums, k) - 1;
	}
};