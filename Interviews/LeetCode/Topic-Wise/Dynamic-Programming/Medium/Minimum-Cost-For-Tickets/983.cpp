#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		auto ub = [&](int val) {
			int answer = days.size(), low = 0, high = days.size() - 1;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (days[mid] > val) {
					answer = mid;
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}

			return answer;
		};

		int cache[days.size() + 1];
		memset(cache, 0, sizeof(cache));
		for (int i = days.size() - 1; i >= 0; i--) {
			cache[i] = cache[i + 1] + costs[0];
			cache[i] = min (cache[i], cache[ub(days[i] + 6)] + costs[1]);
			cache[i] = min (cache[i], cache[ub(days[i] + 29)] + costs[2]);
		}

		return cache[0];
	}
};