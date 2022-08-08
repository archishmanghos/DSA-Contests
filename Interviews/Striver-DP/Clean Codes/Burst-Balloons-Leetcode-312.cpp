#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	n += 2;

	vector<vector<int>> cache(n, vector<int>(n, 0));
	for (int i = n - 2; i >= 1; i--) {
		for (int j = i; j <= n - 2; j++) {
			for (int k = i; k <= j; k++) {
				cache[i][j] = max(cache[i][j], cache[i][k - 1] + cache[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
			}
		}
	}

	cout << cache[1][n - 2];
	return 0;
}