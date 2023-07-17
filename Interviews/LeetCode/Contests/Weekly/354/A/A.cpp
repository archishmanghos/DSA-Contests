#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int sumOfSquares(vector<int>& nums) {
		int answer = 0;
		for (int i = 0; i < nums.size(); i++) {
			if ((int)(nums.size()) % (i + 1) == 0) answer += nums[i] * nums[i];
		}

		return answer;
	}
};