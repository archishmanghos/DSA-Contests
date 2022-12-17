#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double h, t; cin >> h >> t;
	double ans = h / t;
	cout << fixed << setprecision(5) << ans;
	return 0;
}