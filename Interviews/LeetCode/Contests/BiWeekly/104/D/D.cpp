#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int sumOfPower(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int64_t answer = 0, sum = 0, MOD = 1e9 + 7;

		for (int i : nums) answer = (answer + ((i % MOD * i % MOD) % MOD * i) % MOD) % MOD;

		for (int i = 1; i < nums.size(); i++) {
			sum = ((2 * sum) % MOD + nums[i - 1]) % MOD;
			answer = (answer + ((((nums[i] % MOD) * (nums[i] % MOD)) % MOD) * sum) % MOD) % MOD;
		}

		return int(answer % MOD);
	}
};