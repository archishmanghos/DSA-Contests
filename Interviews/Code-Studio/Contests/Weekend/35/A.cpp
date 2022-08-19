#include <bits/stdc++.h>

long long maxPower(vector<int> &a, vector<int> &b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int64_t ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i] * b[i];
	}

	return ans;
}