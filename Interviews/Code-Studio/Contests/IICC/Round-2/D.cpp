#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int steps(int n) {
	int start = 1, ans = 0;
	while (start < n) {
		ans += 1;
		start <<= 1;
	}

	if (start > n) {
		start >>= 1;
		ans -= 1;
	}

	while (start != n) {
		int maxCanGet = 0;
		for (int i = 1; i * i <= start; i++) {
			if (start % i == 0) {
				if (start + (start / i) <= n) maxCanGet = max(maxCanGet, start + (start / i));
				if (start + i <= n) maxCanGet = max(maxCanGet, start + i);
			}
		}
		start = maxCanGet;
		ans += 1;
	}

	return ans;
}

int maximizingMoney(int n, int m, vector<int> &b, vector<int> &c) {
	vector<pair<double, int>> v(n);
	vector<int> minSteps(n);
	for (int i = 0; i < n; i++) {
		minSteps[i] = steps(b[i]);
	}

	for (int i = 0; i < n; i++) {
		double valuePerStep = (minSteps[i] * 1.0) / c[i];
		v[i] = {valuePerStep, i};
	}

	// debug(minSteps)

	sort(v.begin(), v.end());
	int ans1 = 0, ans2 = 0, m1 = m;
	for (int i = n - 1; i >= 0; i--) {
		int index = v[i].second;
		if (c[index] <= m) {
			ans1 += minSteps[index];
			m -= c[index];
		}
	}

	// debug(ans1)
	for (int i = 0; i < n; i++) {
		double energyPerStep = (c[i] * 1.0) / minSteps[i];
		v[i] = {energyPerStep, i};
	}

	// debug(v)
	sort(v.begin(), v.end());
	m = m1;
	for (int i = 0; i < n; i++) {
		int index = v[i].second;
		if (c[index] <= m) {
			ans2 += minSteps[index];
			m -= c[index];
		}
	}

	return min(ans1, ans2);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	int n, m; cin >> n >> m;
	vector<int> b(n), c(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];

	cout << maximizingMoney(n, m, b, c);
	return 0;
}