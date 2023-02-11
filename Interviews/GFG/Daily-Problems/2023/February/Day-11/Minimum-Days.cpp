#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getMinimumDays(int N, string S, vector<int> &P) {
		int equal = 0;
		for (int i = 1; i < N; i++) {
			if (S[i] == S[i - 1]) equal += 1;
		}

		for (int i = 0; i < N; i++) {
			if (equal == 0) return i;
			if (P[i] + 1 < N and S[P[i]] == S[P[i] + 1]) equal -= 1;
			if (P[i] - 1 >= 0 and S[P[i]] == S[P[i] - 1]) equal -= 1;
			S[P[i]] = '?';
		}

		return N;
	}
};