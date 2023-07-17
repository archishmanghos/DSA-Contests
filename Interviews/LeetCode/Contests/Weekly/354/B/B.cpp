#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumBeauty(vector<int>& nums, int k) {
		int answer = 0, low = 1, high = nums.size();
		sort(nums.begin(), nums.end());
		while (low <= high) {
			int mid = (low + high) / 2;
			auto f = [&]() {
				for (int i = mid - 1; i < nums.size(); i++) {
					if (nums[i] - nums[i - mid + 1] <= 2 * k) return true;
				}
				return false;
			};

			if (f()) {
				answer = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		return answer;
	}
};