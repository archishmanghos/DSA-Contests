#include <bits/stdc++.h>
using namespace std;

int N, M, T;

int64_t nCr (int n, int r) {
	int64_t num = 1, den = 1;
	if (r > n) return 0;
	if (n - r < r) r = n - r;
	if (r == 0) return 1;

	while (r) {
		num *= n--, den *= r--;
		int64_t gcd = __gcd(num, den);
		num /= gcd, den /= gcd;
	}

	return num;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	int64_t answer = 0;
	for (int i = 4; i <= min(N, T - 1); i++) {
		answer += nCr(N, i) * nCr(M, (T - i));
	}

	cout << answer;
	return 0;
}