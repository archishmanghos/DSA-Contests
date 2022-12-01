#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, d, x, y; cin >> n >> s >> d;
	bool ans = false;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		ans |= (x < s and y > d);
	}

	cout << (ans ? "Yes" : "No");
	return 0;
}