#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

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

	if (k < n) {
		for (int i = k; i < n; i++) {
			cout << a[i] << ' ';
		}
		for (int i = 0; i < k; i++) {
			cout << 0 << ' ';
		}
	} else {
		for (int i = 0; i < n; i++) {
			cout << 0 << ' ';
		}
	}
	return 0;
}