#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void f(int i, int k, int n, vector<int> cur, vector<vector<int>> &answer) {
		if (k == 0) {
			answer.push_back(cur);
			return;
		}
		if (i == n + 1) return;

		if (n - i + 1 > k) f (i + 1, k, n, cur, answer);
		cur.push_back(i);
		f (i + 1, k - 1, n, cur, answer);
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> answer;
		f (1, k, n, {}, answer);
		return answer;
	}
};