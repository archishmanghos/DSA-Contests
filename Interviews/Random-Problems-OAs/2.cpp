#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

long triplets(vector<int> &d, int t) {
	long ans = 0;
	int n = d.size();
	sort(d.begin(), d.end());
	for (int i = 0; i < (n - 2); i++) {
		int j = i + 1, k = n - 1;
		while (j < k) {
			if ((d[j] + d[k]) <= (t - d[i])) {
				ans += 1LL * (k - j);
				j += 1;
			} else {
				k -= 1;
			}
		}
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t; cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	cin >> t;
	cout << triplets(d, t);
	return 0;
}