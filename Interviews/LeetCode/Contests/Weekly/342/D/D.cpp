#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums) {
		int gcdd = nums[0];
		for (int i : nums) gcdd = __gcd(gcdd, i);
		if (gcdd > 1) return -1;

		int one = 0;
		for (int i : nums) one += i == 1;
		if (one > 0) (nums.size() - one);

		int minL = 1e9;
		for (int i = 0; i + 1 < nums.size(); i++) {
			int gcddd = nums[i];
			for (int j = i; j < nums.size(); j++) {
				gcddd = __gcd(gcddd, nums[j]);
				if (gcddd == 1) {
					minL = min(minL, (j - i + 1));
					break;
				}
			}
		}

		int x = (int)nums.size() + minL - 2;
		return ((int)nums.size() + minL - 2);
	}
};