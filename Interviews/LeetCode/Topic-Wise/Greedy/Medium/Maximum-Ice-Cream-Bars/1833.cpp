#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		sort (costs.begin(), costs.end());
		for (int i = 0; i < costs.size(); i++) {
			if (coins < costs[i]) return i;
			coins -= costs[i];
		}

		return costs.size();
	}
};