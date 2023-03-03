#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int n = needle.size();
		for (int i = 0; i + n <= haystack.size(); i++) {
			if (haystack[i] == needle[0]) {
				int j = i, k = i + n - 1;
				while (j <= k and haystack[j] == needle[j - i] and haystack[k] == needle[k - i]) {
					j++, k--;
				}

				if (j > k) return i;
			}
		}

		return -1;
	}
};