#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countPairs(vector<int>& nums, int target) {
		int answer = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				answer += ((nums[i] + nums[j]) < target);
			}
		}

		return answer;
	}
};