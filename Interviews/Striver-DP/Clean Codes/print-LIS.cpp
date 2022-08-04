#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n, INT_MIN);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<int> cache(n, 1);
	int lis = 1, pos = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				cache[i] = max(cache[i], 1 + cache[j]);
			}
		}
		if (cache[i] > lis) {
			lis = cache[i];
			pos = i;
		}
	}

	vector<int> ans(lis, nums[pos]);
	int start = pos, i = lis - 2;
	while (start >= 0) {
		if (cache[start] == cache[pos] - 1) {
			ans[i--] = nums[start];
			pos = start;
		}
		start--;
	}

	for (int i : ans) cout << i << ' ';
	return 0;
}