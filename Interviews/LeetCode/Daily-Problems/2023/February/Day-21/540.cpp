#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size(), low = 0, high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			bool l = true, r = true;
			l &= (mid - 1 >= 0 and nums[mid - 1] == nums[mid]);
			r &= (mid + 1 < n and nums[mid + 1] == nums[mid]);
			if (!l and !r) return nums[mid];
			int right = n - 1 - mid;

			if (right % 2 == 0) {
				if (r) low = mid + 1;
				else high = mid - 1;
			} else {
				if (r) high = mid - 1;
				else low = mid + 1;
			}
		}

		return -1;
	}
};