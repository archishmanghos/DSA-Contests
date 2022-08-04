#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	sort(nums.begin(), nums.end());
	vector<int> cache(n, 1), hash(n, -1);
	int length = 1, start = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] % nums[j] == 0) {
				if (1 + cache[j] > cache[i]) {
					cache[i] = 1 + cache[j];
					hash[i] = j;
				}
			}
		}
		if (cache[i] > length) {
			length = cache[i];
			start = i;
		}
	}

	vector<int> ans(length, 0);
	while (start != -1) {
		ans[--length] = nums[start];
		start = hash[start];
	}

	for (int i : ans) cout << i << ' ';
	return 0;
}