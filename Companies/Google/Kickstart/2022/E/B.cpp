#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int lowerBound(int x, vector<int> b) {
	int l = 0, r = b.size() - 1;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (b[mid] < x) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	return (b[r] < x ? b.size() : r);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n), b;
	vector<int> mp(1001000, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b.push_back(a[i]);
		mp[a[i]] += 1;
	}

	sort(b.begin(), b.end());
	auto it = unique(b.begin(), b.end());
	b.resize(distance(b.begin(), it));

	for (int i = 0; i < n; i++) {
		int maxPossible = a[i] * 2 + 1;
		int index = lowerBound(maxPossible, b);
		index--;
		if (b[index] == a[i]) {
			if (mp[a[i]] > 1) cout << a[i] << ' ';
			else {
				if (index == 0) cout << -1 << ' ';
				else {
					index--;
					cout << b[index] << ' ';
				}
			}
		} else {
			cout << b[index] << ' ';
		}
	}

	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}