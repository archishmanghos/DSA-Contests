#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int sumOfMultiples(int n) {
		int answer = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0 or i % 5 == 0 or i % 7 == 0) answer += i;
		}

		return answer;
	}
};