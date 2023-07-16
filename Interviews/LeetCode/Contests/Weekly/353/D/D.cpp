#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkArray(vector<int>& nums, int k) {
		if (k == 1) return true;

		int n = nums.size();
		int effect[n], actualEffect = 0;
		for (int i = 0; i < n; i++) {
			if (i - k >= 0) actualEffect -= effect[i - k];
			nums[i] += actualEffect;
			effect[i] = -nums[i];
			actualEffect -= nums[i];
			if (nums[i] < 0) return false;
		}
		if (n - k >= 0) actualEffect -= effect[n - k];

		return actualEffect == 0;
	}
};