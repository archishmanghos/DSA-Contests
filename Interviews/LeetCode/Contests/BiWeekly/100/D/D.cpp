#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long repairCars(vector<int>& ranks, int cars) {
		long long answer = -1, low = 1, high = 1e18;
		while (low <= high) {
			long long mid = low + (high - low) / 2;
			auto f = [&]() {
				long long answer = 0;
				for (int i : ranks) {
					long long x = mid / i;
					answer += (long long)sqrtl(x);
				}

				return (answer >= cars);
			};

			if (f()) {
				answer = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return answer;
	}
};