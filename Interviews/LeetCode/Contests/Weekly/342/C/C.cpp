#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
		vector<int> cnt(52, 0);
		for (int i = 0; i < k - 1; i++) {
			if (nums[i] < 0) cnt[abs(nums[i])]++;
		}

		vector<int> answer;
		for (int i = k - 1; i < nums.size(); i++) {
			if (nums[i] < 0) cnt[abs(nums[i])]++;
			int m = 0;
			for (int j = 50; j >= 1; j--) {
				if (cnt[j] > 0) {
					if (m + cnt[j] >= x) {
						answer.push_back(-j);
						m = -1;
						break;
					}
					m += cnt[j];
				}
			}
			if (m != -1) answer.push_back(0);
			if (nums[i - k + 1] < 0) cnt[abs(nums[i - k + 1])]--;
		}

		return answer;
	}
};