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

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int q; cin >> q;
	int lastChange = -1, lastChanged = -1;
	vector<int> lastIndexChanged(n, -1);
	vector<int> updates = a;
	for (int i = 1; i <= q; i++) {
		int type; cin >> type;
		if (type == 1) {
			int x; cin >> x;
			lastChange = x;
			lastChanged = i;
		} else if (type == 2) {
			int idx, x; cin >> idx >> x;
			idx -= 1;
			if (lastIndexChanged[idx] > lastChanged) {
				updates[idx] += x;
			} else {
				updates[idx] = (lastChange != -1 ? lastChange : a[idx]) + x;
			}
			lastIndexChanged[idx] = i;
		} else {
			int idx; cin >> idx;
			idx -= 1;
			if (lastIndexChanged[idx] > lastChanged) {
				cout << updates[idx] << '\n';
			} else {
				cout << (lastChanged == -1 ? a[idx] : lastChange) << '\n';
			}
		}
	}

	return 0;
}