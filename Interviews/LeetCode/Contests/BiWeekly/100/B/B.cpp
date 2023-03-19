#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximizeGreatness(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int answer = 0;
		for (int i = 0, j = 0; i < nums.size(); i++) {
			if (nums[i] > nums[j]) {
				answer++;
				j++;
			}
		}

		return answer;
	}
};