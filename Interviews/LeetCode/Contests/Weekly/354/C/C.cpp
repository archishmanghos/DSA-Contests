#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumIndex(vector<int>& nums) {
		unordered_map<int, int> ump;
		int dominant, n = nums.size();
		for (int i : nums) {
			ump[i]++;
			if (ump[i] * 2 > n) {
				dominant = i;
			}
		}

		int rightCount = ump[dominant], leftCount = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] == dominant) {
				++leftCount;
				--rightCount;
			}
			if (leftCount * 2 > (i + 1) and rightCount * 2 > (n - i - 1)) return i;
		}

		return -1;
	}
};