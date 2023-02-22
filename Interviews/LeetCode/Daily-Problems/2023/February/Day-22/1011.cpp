#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int shipWithinDays(vector<int>& weights, int days) {
		int low = 1, high = 1e9, answer = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			auto F = [&]() -> bool {
				int sum = 0, dReqd = 1;
				for (int i : weights) {
					if (sum + i > mid) {
						dReqd++;
						if (i > mid) return false;
						sum = i;
					} else {
						sum += i;
					}
				}

				return dReqd <= days;
			};

			if (F()) {
				answer = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return answer;
	}
};