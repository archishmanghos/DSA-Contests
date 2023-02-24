#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		multiset<int> ms;
		for (int i : nums) {
			if (i & 1) i <<= 1;
			ms.insert(i);
		}

		int answer = *ms.rbegin() - *ms.begin();
		while ((*ms.rbegin()) % 2 == 0) {
			int x = *ms.rbegin();
			ms.erase(ms.find(x));
			x >>= 1;
			ms.insert(x);
			answer = min (answer, (*ms.rbegin() - *ms.begin()));
		}

		return answer;
	}
};