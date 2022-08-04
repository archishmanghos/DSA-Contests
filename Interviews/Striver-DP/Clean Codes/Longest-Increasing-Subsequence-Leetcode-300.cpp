#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> nums(n, INT_MIN);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<vector<int>> cache(n + 1, vector<int>(n + 1, 0));
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 0; j--) {
			if (i == n) {
				cache[i][j] = j == 0 or nums[i - 1] > nums[j - 1];
			} else {
				cache[i][j] = cache[i + 1][j];
				if (j == 0 or nums[i - 1] > nums[j - 1]) {
					cache[i][j] = max(cache[i][j], cache[i + 1][i] + 1);
				}
			}
		}
	}

	cout << cache[1][0];
	return 0;
}