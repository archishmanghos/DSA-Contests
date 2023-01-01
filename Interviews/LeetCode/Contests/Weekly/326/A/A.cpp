#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countDigits(int num) {
		int n1 = num, ans = 0;
		while (n1) {
			ans += (num % (n1 % 10)) == 0;
			n1 /= 10;
		}

		return ans;
	}
};