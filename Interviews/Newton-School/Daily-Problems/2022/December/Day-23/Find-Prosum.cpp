#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, suffSum = 0, ans = 0;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) suffSum = (suffSum + a[i]) % MOD;
	}

	for (int i = 1; i <= n; i++) {
		ans = (ans + (a[i] * suffSum) % MOD) % MOD;
		if (i < n) suffSum = (suffSum - a[i + 1] + MOD) % MOD;
	}

	cout << ans;
	return 0;
}