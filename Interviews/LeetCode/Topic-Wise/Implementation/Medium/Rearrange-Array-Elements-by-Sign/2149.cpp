#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		vector<int> pos, neg, ans;
		for (int i : nums) {
			if (i < 0) neg.emplace_back(i);
			else pos.emplace_back(i);
		}

		int i = 0, j = 0, cur = 1;
		while (j < neg.size()) {
			if (cur) ans.emplace_back (pos[i++]);
			else ans.emplace_back (neg[j++]);
			cur ^= 1;
		}

		return ans;
	}
};