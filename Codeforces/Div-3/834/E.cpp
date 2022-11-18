#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int getKilled(vector<int> a, vector<int> v, int h) {
	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		if (h > a[i]) {
			h += a[i] / 2;
		} else {
			while (h <= a[i] and j < v.size()) {
				h *= v[j++];
			}

			if (h > a[i]) {
				h += a[i] / 2;
			} else {
				return i;
			}
		}
	}

	return a.size();
}

void solve() {

	int n, h; cin >> n >> h;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	int ans = getKilled(a, {2, 2, 3}, h);
	ans = max(ans, getKilled(a, {3, 2, 2}, h));
	ans = max(ans, getKilled(a, {2, 3, 2}, h));
	ans = max(ans, getKilled(a, {4, 3}, h));
	ans = max(ans, getKilled(a, {2, 6}, h));
	ans = max(ans, getKilled(a, {6, 2}, h));
	ans = max(ans, getKilled(a, {3, 4}, h));
	ans = max(ans, getKilled(a, {12}, h));
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}