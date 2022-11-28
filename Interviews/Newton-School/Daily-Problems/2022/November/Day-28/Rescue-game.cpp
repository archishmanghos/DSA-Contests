#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n - k; i++) {
		ans += a[i];
	}

	cout << ans;
	return 0;
}