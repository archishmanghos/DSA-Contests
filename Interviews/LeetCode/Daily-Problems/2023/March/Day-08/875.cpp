#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int low = 1, high = *max_element (piles.begin(), piles.end()), answer = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			auto f = [&]() {
				int64_t hour = 0;
				for (int i : piles) hour += (i + mid - 1) / mid;
				return (hour <= 1ll * h);
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