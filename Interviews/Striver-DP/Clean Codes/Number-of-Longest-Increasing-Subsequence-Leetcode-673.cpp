#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<int> cache(n, 1), countLis(n, 1);
	int lis = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				if (1 + cache[j] >= cache[i]) {
					countLis[i] = (1 + cache[j] > cache[i] ? countLis[j] : countLis[i] + countLis[j]);
					cache[i] = 1 + cache[j];
				}
			}
		}
		lis = max(lis, cache[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (lis == cache[i]) ans += countLis[i];
	}

	cout << ans;
	return 0;
}