#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long countSubarrays(vector<int>& nums, int minK, int maxK) {
		int minMinK = -1, minMaxK = -1, i = 0, j = 0;
		int minn = 1e7, maxx = -1e7;
		long long answer = 0;
		for ( ; j < nums.size(); j++) {
			if (nums[j] < minK or nums[j] > maxK) {
				i = j + 1;
				minn = 1e7, maxx = -1e7;
				minMinK = -1, minMaxK = -1;
				continue;
			} else {
				minn = min (minn, nums[j]);
				maxx = max (maxx, nums[j]);
				if (nums[j] == minK) minMinK = j;
				if (nums[j] == maxK) minMaxK = j;
				if (minn == minK and maxx == maxK) answer += 0ll + min(minMinK, minMaxK) - i + 1;
			}
		}

		return answer;
	}
};