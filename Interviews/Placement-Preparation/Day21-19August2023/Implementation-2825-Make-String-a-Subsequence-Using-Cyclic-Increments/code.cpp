#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canMakeSubsequence(string str1, string str2) {
		auto getPre = [](char c) {
			if (c == 'a') return 'z';
			return (char)(c - 1);
		};

		string newStr = str2;
		for (int j = 0, k = 0; j < str1.size(); j++) {
			if (k == newStr.size()) return true;
			if (str1[j] == newStr[k]) k++;
		}


		for (int j = 0; j < str2.size(); j++) newStr[j] = getPre(newStr[j]);
		int k = 0;
		for (int j = 0; j < str1.size(); j++) {
			if (k == newStr.size()) return true;
			if (str1[j] == newStr[k] or str1[j] == str2[k]) k++;
		}

		return (k == (int)newStr.size());
	}
};