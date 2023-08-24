#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (nums[mid] == target) return mid;
			if (mid - 1 >= low and nums[low] <= nums[mid - 1]) {
				if (nums[low] <= target and target <= nums[mid - 1]) high = mid - 1;
				else low = mid + 1;
			} else if (mid + 1 <= high) {
				if (nums[mid + 1] <= target and target <= nums[high]) low = mid + 1;
				else high = mid - 1;
			} else break;
		}

		return -1;
	}
};