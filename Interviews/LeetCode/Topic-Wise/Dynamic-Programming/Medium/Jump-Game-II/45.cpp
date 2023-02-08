#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size(), cache[n];
		cache[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) {
			cache[i] = int(1e9);
			for (int j = 1; j <= nums[i]; j++) {
				if (i + j < n) {
					cache[i] = min(cache[i], cache[i + j] + 1);
				} else break;
			}
		}

		return cache[0];
	}
};