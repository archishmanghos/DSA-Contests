#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int tribonacci(int n) {
		int T[3];
		T[0] = 0, T[1] = T[2] = 1;
		if (n < 3) return T[n];
		for (int i = 3; i <= n; i++) {
			int answer = T[0] + T[1] + T[2];
			T[0] = T[1];
			T[1] = T[2];
			T[2] = answer;
		}

		return T[2];
	}
};