#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int differenceOfSum(vector<int>& nums) {
		int64_t sum = 0, digitSum = 0;

		auto sod = [](int a) {
			int answer = 0;
			while (a) {
				answer += a % 10;
				a /= 10;
			}

			return answer;
		};

		for (int i : nums) {
			sum += i;
			digitSum += sod (i);
		}

		return abs(sum - digitSum);
	}
};