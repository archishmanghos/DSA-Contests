#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		vector<int> answer (spells.size());
		int i = 0;
		sort(potions.begin(), potions.end());
		for (int spell : spells) {
			long long factor = (success + spell - 1) / spell;
			auto it = lower_bound(potions.begin(), potions.end(), factor);
			if (it == potions.end()) answer[i++] = 0;
			else answer[i++] = potions.size() - (it - potions.begin());
		}

		return answer;
	}
};