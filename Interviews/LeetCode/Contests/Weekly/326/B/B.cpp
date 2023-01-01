#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int distinctPrimeFactors(vector<int>& nums) {
		set<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 2; j * j <= nums[i]; j++) {
				if (nums[i] % j == 0) {
					while (nums[i] % j == 0) nums[i] /= j;
					ans.insert(j);
				}
			}
			if (nums[i] > 1) ans.insert(nums[i]);
		}

		return ans.size();
	}
};