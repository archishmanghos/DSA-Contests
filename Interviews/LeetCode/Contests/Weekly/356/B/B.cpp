#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countCompleteSubarrays(vector<int>& nums) {
		int answer = 0;
		set<int> s;
		for (int j : nums) s.insert(j);
		for (int i = 0; i < nums.size(); i++) {
			set<int> x;
			for (int k = i; k < nums.size(); k++) {
				x.insert(nums[k]);
				if (x.size() == s.size()) {
					answer += nums.size() - k;
					break;
				}
			}
		}

		return answer;
	}
};