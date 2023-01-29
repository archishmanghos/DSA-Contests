#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int64_t BinExp(int64_t a, int n, int mod = 1e9 + 7) {
		int64_t ans = 1;
		while (n > 0) {
			if (n & 1) {
				ans = ((ans % mod) * (a % mod)) % mod;
				--n;
			}
			else {
				a = ((a % mod) * (a % mod)) % mod;
				n /= 2;
			}
		}
		return ans;
	}
	int monkeyMove(int n) {
		int MOD = 1e9 + 7;
		int64_t answer = 1;
		answer = BinExp(2ll, n);
		answer = (answer - 2 + MOD) % MOD;
		return int(answer);
	}
};