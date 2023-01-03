#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int colsToDelete = 0;
		for (int i = 0; i < strs[0].size(); i++) {
			for (int j = 1; j < strs.size(); j++) {
				if (strs[j][i] < strs[j - 1][i]) {
					colsToDelete += 1;
					break;
				}
			}
		}

		return colsToDelete;
	}
};