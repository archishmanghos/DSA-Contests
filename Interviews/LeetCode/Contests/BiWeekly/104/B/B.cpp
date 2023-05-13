#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int matrixSum(vector<vector<int>>& nums) {
		int answer = 0;
		for (int i = 0; i < nums.size(); i++) sort(nums[i].begin(), nums[i].end());
		for (int i = 0; i < nums[0].size(); i++) {
			int maxx = 0;
			for (int j = 0; j < nums.size(); j++) {
				maxx = max(maxx, nums[j][i]);
			}
			answer += maxx;
		}

		return answer;
	}
};