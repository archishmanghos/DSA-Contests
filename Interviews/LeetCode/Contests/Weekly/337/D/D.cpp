#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findSmallestInteger(vector<int>& nums, int value) {
		unordered_map<int, int> cnt;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < 0) nums[i] = nums[i] - (value * ((nums[i] - value + 1) / value));
			cnt[nums[i] % value]++;
		}

		int j = 0;
		for (int j = 0; ; j++) {
			if (!cnt[j % value]) return j;
			cnt[j % value]--;
		}
		return -1;
	}
};