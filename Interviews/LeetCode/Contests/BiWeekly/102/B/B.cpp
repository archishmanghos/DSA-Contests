#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<long long> findPrefixScore(vector<int>& nums) {
		vector<long long> answer(nums.size());
		long long sum = 0, maxx = 0;
		for (int i = 0; i < nums.size(); i++) {
			maxx = max(maxx, 1ll * nums[i]);
			sum += nums[i] + maxx;
			answer[i] = sum;
		}

		return answer;
	}
};