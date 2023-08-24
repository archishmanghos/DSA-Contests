#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
		int n = nums1.size();
		vector<vector<int>> nums(n);
		for (int i = 0; i < n; i++) nums[i] = {nums2[i], nums1[i]};
		sort(nums.begin(), nums.end());


		int sumA = accumulate(nums1.begin(), nums1.end(), 0);
		int sumB = accumulate(nums2.begin(), nums2.end(), 0);

		if (sumA <= x) return 0;

		int answer = -1, low = 0, high = n;
		while (low <= high) {
			int mid = (low + high) / 2;
			int m = max(1, mid);
			int cache[n][m][2];
			memset(cache, -1, sizeof(cache));

			function<int(int, int, int, int)> dp = [&](int idx, int reset, int zero, int time) {
				if (idx == n) return 0;
				int &answer = cache[idx][reset][zero];
				if (answer != -1) return answer;

				answer = 0;
				if (n - idx > (reset + zero)) answer = dp(idx + 1, reset, zero, time);
				if (reset > 0) answer = max(answer, dp(idx + 1, reset - 1, zero, time) + (nums[idx][1] + (time - reset) * nums[idx][0]));
				else if (zero > 0) answer = max(answer, dp(idx + 1, reset, zero - 1, time) + (nums[idx][1] + time * nums[idx][0]));

				return answer;
			};

			int64_t sumIfNoDeletions = sumA + mid * sumB;
			int64_t deductedSum = dp(0, max(0, mid - 1), min(1, mid), mid);
			int64_t effectiveSum = sumIfNoDeletions - deductedSum;
			if (effectiveSum <= x) {
				answer = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return answer;
	}
};