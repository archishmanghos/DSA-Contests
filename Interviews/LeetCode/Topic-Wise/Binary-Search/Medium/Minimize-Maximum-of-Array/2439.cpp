#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimizeArrayValue(vector<int>& nums) {
		int low = *min_element(nums.begin(), nums.end());
		int high = *max_element(nums.begin(), nums.end());
		int answer = high;
		while (low <= high) {
			int mid = (low + high) / 2;
			auto f = [&]() -> bool {
				if (nums[0] > mid) return false;
				long lastExtra = 0;
				for (int i = nums.size() - 1; i >= 0; i--) lastExtra = max(0l, (nums[i] + lastExtra) - mid);
				return lastExtra == 0l;
			};

			if (f()) {
				answer = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return answer;
	}
};