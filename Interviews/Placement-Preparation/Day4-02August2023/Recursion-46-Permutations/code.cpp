#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> answer;
		function<void(vector<int>, int)> f = [&](vector<int> cur, int mask) {
			if (mask == (1 << (int)nums.size()) - 1) {
				answer.push_back(cur);
				return;
			}

			for (int i = 0; i < nums.size(); i++) {
				if (!(mask & (1 << i))) {
					cur.push_back(nums[i]);
					f(cur, mask | (1 << i));
					cur.pop_back();
				}
			}
		};

		f({}, 0);
		return answer;
	}
};