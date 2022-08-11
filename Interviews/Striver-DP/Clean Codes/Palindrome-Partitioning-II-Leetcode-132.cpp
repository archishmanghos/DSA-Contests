#include <bits/stdc++.h>
using namespace std;

bool checkPal(int l, int r, string &s) {
	while (l < r) {
		if (s[l++] != s[r--]) return false;
	}

	return true;
}

int32_t main() {

	string s; cin >> s;
	int n = s.size();

	vector<int> cache(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		int ans = INT_MAX;
		for (int j = i; j < n; j++) {
			if (checkPal(i, j, s)) {
				ans = min(ans, cache[j + 1] + 1);
			}
		}
		cache[i] = ans;
	}

	cout << cache[0] - 1;
	return 0;
}