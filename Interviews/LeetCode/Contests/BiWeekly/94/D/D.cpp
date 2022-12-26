#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1e9 + 7;

class Solution {
public:
	int64_t fact(int64_t n, int64_t mod = 1e9 + 7) {
		int64_t ans = 1;
		for (int64_t i = 1; i <= n; i++) {
			ans = (ans * i) % mod;
		}

		return ans;
	}

	int64_t pow(int64_t a, int64_t b, int64_t m) {
		int64_t ans = 1;
		while (b) {
			if (b & 1)
				ans = (ans * a) % m;
			b /= 2;
			a = (a * a) % m;
		}
		return ans;
	}

	int64_t modinv(int64_t k) {
		return pow(k, MOD - 2, MOD);
	}

	int countAnagrams(string s) {
		string word = "";
		s += ' ';
		int64_t finalAns = 1;
		for (char c : s) {
			if (c == ' ') {
				vector<int64_t> cnt(26, 0);
				int64_t n = word.size();
				for (char ch : word) cnt[ch - 'a'] += 1;

				vector<int64_t> a;
				for (int64_t i = 0; i < 26; i++) {
					if (cnt[i] > 1) a.push_back(cnt[i]);
				}

				int64_t ans = fact(n), mod = 1e9 + 7;
				for (int64_t i : a) {
					int64_t k = fact(i);
					int64_t kl = modinv(k);
					ans = (ans * kl) % mod;
				}
				finalAns = (ans * finalAns) % mod;
				word = "";
			} else {
				word += c;
			}
		}

		return (int)finalAns;
	}
};