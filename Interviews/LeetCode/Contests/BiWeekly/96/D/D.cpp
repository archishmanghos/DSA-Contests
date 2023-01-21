#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isReachable(int targetX, int targetY) {
		while (targetX % 2 == 0) targetX >>= 1;
		while (targetY % 2 == 0) targetY >>= 1;
		return (__gcd(targetX, targetY) == 1);
	}
};