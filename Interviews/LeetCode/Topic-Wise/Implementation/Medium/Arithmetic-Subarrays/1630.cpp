#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		vector<bool> ans (l.size());
		for (int i = 0; i < l.size(); i++) {
			vector<int> temp (r[i] - l[i] + 1);
			for (int j = l[i]; j <= r[i]; j++) temp[j - l[i]] = nums[j];
			sort (temp.begin(), temp.end());
			int diff = temp[1] - temp[0];
			bool ok = true;
			for (int j = 1; j < temp.size(); j++) ok &= temp[j] - temp[j - 1] == diff;

			ans[i] = ok;
		}

		return ans;
	}
};