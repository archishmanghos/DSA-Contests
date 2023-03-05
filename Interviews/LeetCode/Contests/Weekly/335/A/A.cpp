#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int passThePillow(int n, int time) {
		int i = 1, add = 1;
		while (time--) {
			i += add;
			if (i == n + 1) {
				i = n - 1;
				add = -1;
			}
			if (i == 0) {
				i = 2;
				add = 1;
			}
		}

		return i;
	}
};