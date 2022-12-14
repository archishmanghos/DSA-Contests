#include <bits/stdc++.h>
const int mxn = 1e7 + 3;
std::vector<int> sieve(mxn, 1);

class Solution {
private:
	void soe() {
		for (int i = 1; i <= mxn; i++) {
			sieve[i] = i;
		}
		for (int i = 2; i * i <= mxn; i++) {
			if (sieve[i] == i) {
				for (int j = 2 * i; j <= mxn; j += i) {
					sieve[j] = std::min(sieve[j], i);
				}
			}
		}
		for (int i = 2; i * i <= mxn; i++) {
			if (sieve[i] == 1) {
				sieve[i] = i;
				for (int j = i * i; j <= mxn; j += i) {
					if (sieve[j] == 1) {
						sieve[j] = i;
					}
				}
			}
		}
	}

	std::vector<int> pf(int n) {
		std::vector<int> ans;
		while (n > 1) {
			int factor = sieve[n];
			ans.push_back(factor);
			while (n % factor == 0) {
				n /= factor;
			}
		}

		return ans;
	}

	int minK(int n, int x) {
		std::vector<int> factors = pf(n);
		int ans = 1e9;
		for (int factor : factors) {
			ans = std::min(ans, factor - (x % factor));
		}

		return ans;
	}

public:
	void init() {
		soe();
	}

	int getAns(int n, int x) {
		return minK(n, x);
	}
} obj;

void solve() {
	int a, b; std::cin >> a >> b;
	if (std::__gcd(a, b) > 1) {
		std::cout << 0 << '\n';
		return;
	}

	if (a % 2 and b % 2) {
		std::cout << 1 << '\n';
		return;
	}

	if (a > b) {
		std::swap(a, b);
	}

	if (b - a == 1) {
		std::cout << -1 << '\n';
		return;
	}

	std::cout << obj.getAns(b - a, a) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	obj.init();
	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}