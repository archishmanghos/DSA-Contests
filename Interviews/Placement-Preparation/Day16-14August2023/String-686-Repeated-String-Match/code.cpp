#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int add(int a, int b, int p = 31) {
		long c = a + b;
		if (c >= p) c -= p;
		return c;
	}

	int sub(int a, int b, int p = 31) {
		long c = a - b;
		if (c < 0) c += p;
		return c;
	}

	int mul(int a, int b, int p = 31) {
		return (a * 1ll * b) % p;
	}

	int repeatedStringMatch(string a, string b) {
		auto getHash = [&](string s, int mod = 1e9 + 7) {
			int hash = 0;
			for (int i = s.size() - 1, j = 1; i >= 0; i--, j = mul(j, 10)) {
				hash = add(hash, mul(((s[i] - 'a') + 1), j));
			}
			return hash;
		};

		int n1 = a.size(), n2 = b.size(), repeat = 1;
		string x = a;
		while (x.size() < b.size()) {
			x += a;
			repeat++;
		}
		if (x == b) return repeat;
		int hash = getHash(b);

		auto findPattern = [&](string x, string y, int mod = 1e9 + 7) {
			long rollingHash = 0, i, j, n = x.size();
			for (i = n - 2, j = 1; i >= 0; i--, j = mul(j, 10)) {
				rollingHash = add(rollingHash, mul((y[i] - 'a') + 1, mul(j, 10)));
			}

			for (i = n - 1; i < y.size(); i++) {
				if (i - n >= 0) {
					rollingHash = mul(sub(rollingHash, mul(j, (y[i - n] - 'a') + 1)), 10);
				}

				rollingHash = add(rollingHash, (y[i] - 'a') + 1);
				if (rollingHash == hash) if (x == y.substr(i - n + 1, n)) return true;
			}

			return false;
		};

		if (findPattern(b, x)) return repeat;
		if (findPattern(b, x + a)) return repeat + 1;
		return -1;
	}
};