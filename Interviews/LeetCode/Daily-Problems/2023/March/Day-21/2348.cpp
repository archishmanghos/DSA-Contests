#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long zeroFilledSubarray(vector<int>& nums) {
		long long answer = 0;
		int count = 0;
		for (int i : nums) {
			if (i != 0) {
				answer += 1ll * count * (count + 1) / 2;
				count = 0;
			} else {
				count++;
			}
		}

		answer += 1ll * count * (count + 1) / 2;
		return answer;
	}
};