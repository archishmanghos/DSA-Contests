#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumSum(int n, int k) {
		int answer = 0, sz = 0;
		unordered_map<int, bool> ump;
		for (int i = 1; sz < n; i++) {
			if (ump.find(k - i) == ump.end()) {
				answer += i;
				ump[i] = true;
				sz++;
			}
		}

		return answer;
	}
};