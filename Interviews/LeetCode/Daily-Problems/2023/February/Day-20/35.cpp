#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1, answer = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] < target) {
				answer = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}

		return answer + 1;
	}
};