#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int solve(int a, int b) {
		bool setA_unsetB = false, setB_unsetA = false;
		for (int i = 0; i <= 30; i++) {
			bool setA = (a >> i) & 1, setB = (b >> i) & 1;
			if (setA and !setB) setA_unsetB = true;
			if (!setA and setB) setB_unsetA = true;
		}

		if (setA_unsetB and setB_unsetA) return 2;
		if (setA_unsetB or setB_unsetA) return 1;
		return 0;
	}
};