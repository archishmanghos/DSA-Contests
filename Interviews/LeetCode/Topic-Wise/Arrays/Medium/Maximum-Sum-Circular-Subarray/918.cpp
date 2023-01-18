#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size(), sumMin = 0, minSum = 0, sumMax = 0, maxSum = 0, totSum = 0, maxx = -1e9;
		for (int i = 0; i < n; i++) {
			sumMin += nums[i];
			sumMax += nums[i];
			totSum += nums[i];
			if (sumMin > 0) sumMin = 0;
			if (sumMax < 0) sumMax = 0;
			minSum = min (minSum, sumMin);
			maxSum = max (maxSum, sumMax);
			maxx = max (maxx, nums[i]);
		}

		return (maxx < 0 ? maxx : max (totSum - minSum, maxSum));
	}
};