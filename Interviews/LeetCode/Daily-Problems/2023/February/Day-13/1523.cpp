#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countOdds(int low, int high) {
		return ((low & 1) ? (high - low) / 2 + 1 : (high - low + 1) / 2);
	}
};