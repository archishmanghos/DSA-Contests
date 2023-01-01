#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	const int mod = 1e9 + 7;
	int64_t xgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
		if (a == 0) {
			x = 0;
			y = 1;
			return b;
		}
		int64_t x1, y1;
		int64_t d = xgcd(b % a, a, x1, y1);
		x = y1 - (b / a) * x1;
		y = x1;
		return d;
	}

	int64_t modular_inverse(int64_t a, int64_t m = 1e9 + 7) {
		int64_t x, y;
		int64_t g = xgcd(a, m, x, y);
		if (g != 1)
			return -1;
		else {
			x = (x % m + m) % m;
			return x;
		}
	}

	void preCalculate(int64_t n, vector<int64_t> &fact, int64_t mod = 1e9 + 7) {
		fact[0] = 1;
		for (int64_t i = 1; i <= n; i++)
			fact[i] = ((int64_t)(fact[i - 1]) * (int64_t)i) % mod;
	}

	int64_t nCr(int64_t n, int64_t r, vector<int64_t> &fact) {
		return ((fact[n] * (modular_inverse(fact[n - r]) % mod) % mod) * (modular_inverse(fact[r]) % mod)) % mod;
	}

	int compute_value(int n) {
		vector<int64_t> fact(n + 1);
		preCalculate(n, fact);
		int64_t ans = 0;
		for (int i = 0; i <= n; i++) {
			int64_t choose = nCr(n, i, fact);
			ans = (ans + (choose * choose) % mod) % mod;
		}
		return ans;
	}
};