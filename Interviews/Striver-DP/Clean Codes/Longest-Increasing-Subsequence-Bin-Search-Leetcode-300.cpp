#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n, INT_MIN);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<int> lisNotLis;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(lisNotLis.begin(), lisNotLis.end(), nums[i]);
		if (it == lisNotLis.end()) {
			lisNotLis.push_back(nums[i]);
		} else {
			int index = it - lisNotLis.begin();
			lisNotLis[index] = nums[i];
		}
	}

	cout << lisNotLis.size();
	return 0;
}