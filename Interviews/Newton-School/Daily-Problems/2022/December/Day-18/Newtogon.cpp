#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, maxx = 0, sum = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		maxx = max(maxx, a);
		sum += a;
	}

	if ((sum - maxx) > maxx) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}