#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		long long low = 0, high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips, answer = -1;

		while (low <= high) {
			long long mid = low + (high - low) / 2;
			auto f = [&]() {
				long long trips = 0;
				for (int i : time) trips += mid / i;
				return (trips >= totalTrips);
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