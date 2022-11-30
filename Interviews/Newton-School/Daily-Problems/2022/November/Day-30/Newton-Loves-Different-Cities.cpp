#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, a, ans = -1; cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (ans == -1) {
			ans = abs(x - a);
		} else {
			ans = __gcd(ans, abs(x - a));
		}
	}

	cout << ans;
	return 0;
}