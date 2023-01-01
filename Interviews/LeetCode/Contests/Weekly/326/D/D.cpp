#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6 + 3;

class Solution {
public:
	vector<int> sieve;
	void preCompute () {
		sieve[0] = sieve[1] = 0;
		for (int i = 2; i * i <= mxN; i++) {
			if (sieve[i]) {
				for (int j = i * i; j <= mxN; j += i) sieve[j] = 0;
			}
		}
	}
	vector<int> closestPrimes(int left, int right) {
		sieve.assign(mxN, 1);
		preCompute();

		int lastPrime = -1, dist = 1e9;
		vector<int> ans = { -1, -1};
		for (int i = left; i <= right; i++) {
			if (sieve[i]) {
				if (lastPrime != -1) {
					if (i - lastPrime < dist) {
						dist = i - lastPrime;
						ans = {lastPrime, i};
					}
				}
				lastPrime = i;
			}
		}

		return ans;
	}
};