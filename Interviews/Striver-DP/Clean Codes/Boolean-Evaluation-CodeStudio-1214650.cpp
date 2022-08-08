#include <bits/stdc++.h>
using namespace std;

int64_t mul(int64_t a, int64_t b, int mod = 1e9 + 7) {
	return ((a % mod) * (b % mod)) % mod;
}

int64_t add(int64_t a, int64_t b, int mod = 1e9 + 7) {
	return ((a % mod) + (b % mod)) % mod;
}

int getWays(char op, bool wantTrue, int64_t lt, int64_t rt, int64_t lf, int64_t rf) {
	if (op == '&') {
		if (wantTrue) return mul(lt, rt);
		return add(mul(lf, rf), add(mul(lt, rf), mul(lf, rt)));
	} else if (op == '|') {
		if (wantTrue) return add(mul(lt, rt), add(mul(lt, rf), mul(lf, rt)));
		return mul(lf, rf);
	} else {
		if (wantTrue) return add(mul(lt, rf), mul(lf, rt));
		return add(mul(lf, rf), mul(lt, rt));
	}

	return 0;
}

int32_t main() {

	string s; cin >> s;
	int n = s.size();

	vector<vector<vector<int>>> cache(n, vector<vector<int>>(n, vector<int>(2, 0)));
	for (int i = n - 1; i >= 0; i -= 2) {
		for (int j = 0; j < n; j += 2) {
			if (i == j) {
				cache[i][j][0] = s[i] == 'F';
				cache[i][j][1] = s[i] == 'T';
			} else {
				for (int k = i + 1; k < j; k += 2) {
					cache[i][j][0] = add(cache[i][j][0], getWays(s[k], 0, cache[i][k - 1][1], cache[k + 1][j][1], cache[i][k - 1][0], cache[k + 1][j][0]));
					cache[i][j][1] = add(cache[i][j][1], getWays(s[k], 1, cache[i][k - 1][1], cache[k + 1][j][1], cache[i][k - 1][0], cache[k + 1][j][0]));
				}
			}
		}
	}

	cout << cache[0][n - 1][1];
	return 0;
}