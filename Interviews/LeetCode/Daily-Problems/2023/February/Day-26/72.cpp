#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n1 = word1.size(), n2 = word2.size();
		int cache[n1 + 2][n2 + 2];
		memset (cache, 0, sizeof (cache));
		for (int i = 0; i <= n1; i++) cache[i][n2] = n1 - i;
		for (int j = 0; j <= n2; j++) cache[n1][j] = n2 - j;
		for (int i = n1 - 1; i >= 0; i--) {
			for (int j = n2 - 1; j >= 0; j--) {
				if (word1[i] == word2[j]) cache[i][j] = cache[i + 1][j + 1];
				else {
					cache[i][j] = min (cache[i + 1][j + 1], min (cache[i + 1][j], cache[i][j + 1])) + 1;
				}
			}
		}

		return cache[0][0];
	}
};