#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isAcronym(vector<string>& words, string s) {
		string w = "";
		for (string c : words) w += c[0];
		return w == s;
	}
};