#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
		int cache[nums1.size()][3];
		memset(cache, -1, sizeof(cache));

		function<int(int, int)> dp = [&](int idx, int pre) {
			if (idx == nums1.size()) return 0;

			int &answer = cache[idx][pre];
			if (answer != -1) return answer;

			answer = 0;
			if (pre == 0) {
				answer = max(dp(idx + 1, 0), 1 + max(dp(idx + 1, 1), dp(idx + 1, 2)));
			} else {
				int x = !(pre - 1) ? nums1[idx - 1] : nums2[idx - 1];
				if (nums1[idx] >= x) answer = 1 + dp(idx + 1, 1);
				if (nums2[idx] >= x) answer = max(answer, 1 + dp(idx + 1, 2));
			}

			return answer;
		};

		return dp(0, 0);
	}
};