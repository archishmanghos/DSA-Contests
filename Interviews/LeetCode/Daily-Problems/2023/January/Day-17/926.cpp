#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int n = s.size(), sum0 = 0;
		for (char c : s) sum0 += c == '0';
		vector<int> pref0 (n, 0), pref1 (n, 0);

		for (int i = 0; i < n; i++) {
			pref0[i] = s[i] == '0';
			pref1[i] = s[i] == '1';
			if (i > 0) pref0[i] += pref0[i - 1];
			if (i > 0) pref1[i] += pref1[i - 1];
		}

		int answer = sum0;
		for (int i = 0; i < n; i++) {
			int toZero = pref1[i];
			int toOne = sum0 - pref0[i];
			answer = min (answer, toZero + toOne);
		}

		return answer;
	}
};