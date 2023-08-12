#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int answer = 0;
		unordered_map<string, int> ump;
		ump["I"] = 1;
		ump["II"] = 2;
		ump["III"] = 3;
		ump["IV"] = 4;
		ump["V"] = 5;
		ump["IX"] = 9;
		ump["X"] = 10;
		ump["XL"] = 40;
		ump["L"] = 50;
		ump["XC"] = 90;
		ump["C"] = 100;
		ump["CD"] = 400;
		ump["D"] = 500;
		ump["CM"] = 900;
		ump["M"] = 1000;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'I') {
				if (i + 1 < s.size()) {
					if (s[i + 1] == 'V') {
						answer += 4;
						i++;
					} else if (s[i + 1] == 'X') {
						answer += 9;
						i++;
					} else answer++;
				} else answer++;
			} else if (s[i] == 'V') {
				answer += 5;
			} else if (s[i] == 'X') {
				if (i + 1 < s.size()) {
					if (s[i + 1] == 'L') {
						answer += 40;
						i++;
					} else if (s[i + 1] == 'C') {
						answer + a = 90;
						i++;
					} else answer += 10;
				} else answer += 10;
			} else if (s[i] == 'L') {
				answer += 50;
			} else if (s[i] == 'C') {
				if (i + 1 < s.size()) {
					if (s[i + 1] == 'D') {
						answer += 400;
						i++;
					} else if (s[i + 1] == 'M') {
						answer += 900;
						i++;
					} else answer += 100;
				} else answer += 100;
			} else if (s[i] == 'D') {
				answer += 500;
			} else {
				answer += 1000;
			}
		}

		return answer;
	}
};