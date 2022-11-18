#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int count0(int n) {
	int ans = 0;
	while (n > 0) {
		if (n % 10 != 0) break;
		ans += 1;
		n /= 10;
	}

	return ans;
}

vector<int> PF(int n) {
	int power2 = 0, power5 = 0;
	while (n % 5 == 0) {
		n /= 5;
		power5 += 1;
	}
	while (n % 2 == 0) {
		n /= 2;
		power2 += 1;
	}

	return {power2, power5};
}

void solve() {

	int n, m; cin >> n >> m;
	int power2 = 0, power5 = 0;
	int n1 = n;
	while (n1 % 2 == 0) {
		power2 += 1;
		n1 >>= 1;
	}

	while (n1 % 5 == 0) {
		power5 += 1;
		n1 /= 5;
	}

	if (power2 < power5) {
		int k = 1;
		while (k * 2 <= m and power2 < power5) {
			k <<= 1;
			power2 += 1;
		}

		while (k * 10 <= m) {
			k *= 10;
		}

		k = (m / k) * k;
		cout << (count0(n * k) == count0(n) ? n * m : n * k) << '\n';
	} else if (power2 > power5) {
		int k = 1;
		while (k * 5 <= m and power2 > power5) {
			k *= 5;
			power5 += 1;
		}

		while (k * 10 <= m) {
			k *= 10;
		}

		k = (m / k) * k;
		cout << (count0(n * k) == count0(n) ? n * m : n * k) << '\n';
	} else {
		int k = 1;
		while (k * 10 <= m) {
			k *= 10;
		}
		k = (m / k) * k;
		cout << (count0(n * k) == count0(n) ? n * m : n * k) << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}