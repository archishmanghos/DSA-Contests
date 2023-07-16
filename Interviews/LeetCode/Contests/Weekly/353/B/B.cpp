#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumJumps(vector<int>& nums, int target) {
		int n = nums.size();
		int cache[n];
		memset(cache, -1, sizeof(cache));
		cache[n - 1] = 0;
		for (int idx = n - 2; idx >= 0; idx--) {
			for (int i = idx + 1; i < n; i++) {
				if (abs(nums[idx] - nums[i]) <= target) {
					if (cache[i] != -1) cache[idx] = max(cache[idx], 1 + cache[i]);
				}
			}
		}

		return (cache[0] == 0 ? -1 : cache[0]);
	}
};