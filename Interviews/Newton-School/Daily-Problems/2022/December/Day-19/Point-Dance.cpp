#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 100100;
int a[mxn], diff[mxn];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	if (m == 1) {
		cout << 0;
		return 0;
	}

	sort(a, a + m);
	for (int i = 1; i < m; i++) {
		diff[i - 1] = a[i - 1] - a[i];
	}

	sort(diff, diff + m);
	int ans = a[m - 1] - a[0];
	for (int i = 0; i < n - 1; i++) {
		ans += diff[i];
	}

	cout << ans;
	return 0;
}
