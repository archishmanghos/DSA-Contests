#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minOperations(int n) {
		int ans = 0;
		if (n & 1) {
			int terms = (n - 1) >> 1;
			ans = terms * (terms + 1);
		} else {
			int terms = n >> 1;
			ans = terms * terms;
		}

		return ans;
	}
};