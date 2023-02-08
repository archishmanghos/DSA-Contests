#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<long long int> countZero(int n, int k, vector<vector<int>>& arr) {
		long long int answer = n * n, rowsRem = n, colsRem = n;
		vector<int> row (n + 2, 1), col (n + 2, 1);
		vector<long long int> ans (k);
		for (int i = 0; i < k; i++) {
			int r = arr[i][0], c = arr[i][1];
			if (row[r] and col[c]) {
				answer -= rowsRem + colsRem - 1;
				row[r] = col[c] = 0;
				rowsRem -= 1;
				colsRem -= 1;
			}
			else if (row[r]) {
				answer -= colsRem;
				row[r] = 0;
				rowsRem -= 1;
			} else if (col[c]) {
				answer -= rowsRem;
				col[c] = 0;
				colsRem -= 1;
			}
			ans[i] = answer;
		}

		return ans;
	}
};