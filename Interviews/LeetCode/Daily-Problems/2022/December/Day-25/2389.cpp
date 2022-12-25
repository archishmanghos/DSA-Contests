#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); i++) nums[i] += nums[i - 1];
		vector<int> ans(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			auto it = upper_bound(nums.begin(), nums.end(), queries[i]);
			it--;
			ans[i] = (it - nums.begin()) + 1;
		}

		return ans;
	}
};