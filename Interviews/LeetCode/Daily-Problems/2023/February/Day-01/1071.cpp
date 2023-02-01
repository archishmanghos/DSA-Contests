#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		int n1 = str1.size(), n2 = str2.size();
		if (n1 > n2) {
			swap (str1, str2);
			swap (n1, n2);
		}

		auto helper = [&](int sz) {
			int i = 0, j = 0, count1 = 0, count2 = 0;
			while (j < n1) {
				if (str1[i] != str1[j] or str1[i] != str2[j]) return -1;
				i = (i + 1) % sz;
				j += 1;
				if (i == 0) count1 += 1, count2 += 1;
			}

			while (j < n2) {
				if (str1[i] != str2[j]) return -1;
				i = (i + 1) % sz;
				j += 1;
				if (i == 0) count2 += 1;
			}

			return min (count1, count2);
		};

		int sizeOfSubstr = -1;
		for (int i = 0; i < n1; i++) {
			if (n1 % (i + 1) == 0 and n2 % (i + 1) == 0) {
				int count = helper (i + 1);
				if (count != -1) sizeOfSubstr = i + 1;
			}
		}

		if (sizeOfSubstr != -1) return str1.substr(0, sizeOfSubstr);
		return "";
	}
};