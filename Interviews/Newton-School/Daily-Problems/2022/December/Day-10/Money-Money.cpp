#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string s;
	double t, ans = 0.0;
	while (n--) {
		cin >> t >> s;
		if (s == "JPY") {
			ans += t;
		} else {
			ans += t * 380000.0;
		}
	}

	cout << fixed << setprecision(8) << ans;
	return 0;
}