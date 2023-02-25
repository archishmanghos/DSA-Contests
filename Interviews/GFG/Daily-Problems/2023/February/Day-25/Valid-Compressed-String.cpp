#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int checkCompressed(string S, string T) {
		int i = 0, j = 0;
		while (i < S.size() and j < T.size()) {
			if (S[i] == T[j]) {
				i++, j++;
				continue;
			}

			if (T[j] >= 'A' and T[j] <= 'Z') return 0;
			string shift = "";
			while (j < T.size() and T[j] >= '0' and T[j] <= '9') shift += T[j++];
			int shiftNum = 0, k = 1;
			while (shift.size()) {
				shiftNum += (shift.back() - '0') * k;
				k *= 10;
				shift.pop_back();
			}

			i += shiftNum;
		}

		return (i == S.size() and j == T.size());
	}
};