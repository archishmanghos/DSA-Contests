#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> evenOddBit(int n) {
		vector<int> answer(2, 0);
		for (int i = 0; i <= 10; i++) {
			if (n & (1 << i)) {
				answer[i % 2]++;
			}
		}

		return answer;
	}
};