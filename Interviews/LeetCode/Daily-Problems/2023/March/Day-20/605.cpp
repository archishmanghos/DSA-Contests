#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int maxFlowers = 0, zero = 0;
		bool one = false;
		for (int i : flowerbed) {
			if (i == 1) {
				if (!one) maxFlowers += zero / 2;
				else maxFlowers += max(0, (zero - 1) / 2);
				one = true;
				zero = 0;
			} else {
				zero++;
			}
		}

		if (one) maxFlowers += zero / 2;
		else maxFlowers += (zero + 1) / 2;
		return (maxFlowers >= n);
	}
};
