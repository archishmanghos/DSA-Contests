#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> answer;
		int i = 0, j = n;
		while (i < n) {
			answer.push_back(nums[i++]);
			answer.push_back(nums[j++]);
		}

		return answer;
	}
};