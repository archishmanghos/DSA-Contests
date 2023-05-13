#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long maximumOr(vector<int>& nums, int k) {
		int n = nums.size();
		long long pref[n + 5], suff[n + 5], answer = 0, power = (1ll << k);

		pref[0] = 0;
		for (int i = 0; i < n; i++) pref[i + 1] = pref[i] | (1ll * nums[i]);
		suff[n] = 0;
		for (int i = n - 1; i >= 0; i--) suff[i] = suff[i + 1] | (1ll * nums[i]);

		for (int i = 0; i < n; i++) {
			long long x = pref[i], y = 1ll * nums[i] * power, z = suff[i + 1];
			long long temp = x | y;
			temp |= z;
			answer = max(answer, temp);
		}

		return answer;
	}
};

// https://www.geeksforgeeks.org/maximize-the-bitwise-or-of-an-array/