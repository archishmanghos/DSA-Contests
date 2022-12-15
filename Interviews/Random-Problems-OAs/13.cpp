#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int add(int a, int b, int p = 1e9 + 7) {
	int c = a + b;
	if (c >= p)
		c -= p;
	return c;
}

int solution(vector<int> &x, vector<int> &y) {
	int n = x.size();
	unordered_map<int, int> ump;
	int ans = 0, lcmm = 1;
	for (int i = 0; i < n; i++) {
		lcmm = (lcmm * y[i]) / __gcd(lcmm, y[i]);
	}

	for (int i = 0; i < n; i++) {
		x[i] = x[i] * (lcmm / y[i]);
		y[i] = lcmm;
		int makeItOne = lcmm - x[i];
		if (ump.find(makeItOne) != ump.end()) {
			ans = add(ans, ump[makeItOne]);
		}
		ump[x[i]] += 1;
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	cout << solution(x, y);
	return 0;
}