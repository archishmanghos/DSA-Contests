#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		set<long> s, answer;
		s.insert(1);

		while (answer.size() < n) {
			int smallestUgly = *s.begin(); s.erase((*s.begin()));
			answer.insert(smallestUgly);
			s.insert(smallestUgly * 2ll);
			s.insert(smallestUgly * 3ll);
			s.insert(smallestUgly * 5ll);
		}

		return *answer.rbegin();
	}
};