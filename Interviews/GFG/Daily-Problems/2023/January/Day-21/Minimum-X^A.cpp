#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minVal(int a, int b) {
		int setBits = 0;
		for (int i = 0; i < 32; i++) setBits += ((b >> i) & 1);

		int answer = 0;
		for (int i = 31; i >= 0; i--) {
			if (setBits == 0) break;
			if ((a >> i) & 1) {
				answer ^= (1 << i);
				setBits -= 1;
			}
		}

		if (setBits) {
			for (int i = 0; i < 32; i++) {
				if (setBits == 0) break;
				if (!((answer >> i) & 1)) {
					answer ^= (1 << i);
					setBits -= 1;
				}
			}
		}

		return answer;
	}
};