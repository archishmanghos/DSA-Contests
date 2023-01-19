#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		int n = nums.size(), answer = 0;
		int64_t sum = 0;
		vector<int> prefSum(n, 0), freq (k, 0);
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			if (sum < 0) {
				int div = (abs(sum) + k - 1) / k;
				sum += div * k;
			}
			prefSum[i] = sum % k;
			if (prefSum[i] == 0) answer += freq[0] + 1;
			else answer += freq[prefSum[i]];
			freq[prefSum[i]] += 1;
		}

		return answer;
	}
};