#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool makeStringsEqual(string s, string target) {
		int cnt1[2] = {0}, cnt2[2] = {0};
		for (char c : s) cnt1[c - '0'] += 1;
		for (char c : target) cnt2[c - '0'] += 1;

		if (cnt1[1] == 0) return cnt2[1] == 0;
		if (cnt2[1] == 0) return cnt1[1] == 0;
		return true;
	}
};