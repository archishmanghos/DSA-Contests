#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool hasAns(vector<int> &price, int k, int n) {
		int start = price[0];
		k -= 1;
		for (int i = 1; i < price.size(); i++) {
			if (price[i] - start >= n) {
				start = price[i];
				k -= 1;
			}
		}

		return k <= 0;
	}
	int maximumTastiness(vector<int>& price, int k) {
		int low = 0, high = 1e9, ans = 0;
		sort(price.begin(), price.end());
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int hAns = hasAns(price, k, mid);
			if (hAns) {
				ans = mid;
				low = mid + 1;
			} else high = mid - 1;
		}

		return ans;
	}
};