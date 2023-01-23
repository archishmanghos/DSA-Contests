#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> trusts (n + 1, 0), isTrusted (n + 1, 0);
		for (auto edge : trust) {
			trusts[edge[0]] += 1;
			isTrusted[edge[1]] += 1;
		}

		for (int i = 1; i <= n; i++) if (trusts[i] == 0 and isTrusted[i] == n - 1) return i;
		return -1;
	}
};