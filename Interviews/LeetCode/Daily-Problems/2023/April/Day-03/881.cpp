#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		multiset<int> ms;
		for (int lok : people) ms.insert(lok);

		int answer = 0;
		while (ms.size()) {
			answer++;
			int first = *ms.begin();
			ms.erase(ms.find(first));
			if (ms.size()) {
				int spaceLeft = limit - first;
				auto it = ms.upper_bound(spaceLeft);
				if (it != ms.begin()) {
					it--;
					ms.erase(it);
				}
			}
		}

		return answer;
	}
};