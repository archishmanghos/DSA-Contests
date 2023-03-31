#include <bits/stdc++.h>
using namespace std;

class queryGrid {
	int apple[55][55];
public:
	void build (vector<string> &pizza) {
		for (int i = 0; i < pizza.size(); i++) {
			for (int j = 0; j < pizza[0].size(); j++) {
				apple[i][j] = (pizza[i][j] == 'A');
				apple[i][j] += (i - 1 >= 0 ? apple[i - 1][j] : 0);
				apple[i][j] += (j - 1 >= 0 ? apple[i][j - 1] : 0);
				apple[i][j] -= (i - 1 >= 0 and j - 1 >= 0 ? apple[i - 1][j - 1] : 0);
			}
		}
	}

	bool query (int r_start, int c_start, int r_end, int c_end) {
		int apples = apple[r_end][c_end];
		if (r_start - 1 >= 0) apples -= apple[r_start - 1][c_end];
		if (c_start - 1 >= 0) apples -= apple[r_end][c_start - 1];
		if (r_start - 1 >= 0 and c_start - 1 >= 0) apples += apple[r_start - 1][c_start - 1];
		return apples >= 1;
	}
};

class Solution {
	queryGrid qg;
	int cache[50][50][10];
public:
	int dp (int r, int c, int k, int n, int m, int MOD = 1e9 + 7) {
		if (k == 0) return qg.query(r, c, n - 1, m - 1);
		int &answer = cache[r][c][k];
		if (answer != -1) return answer;

		answer = 0;
		for (int i = r; i + 1 < n; i++) {
			if (qg.query(r, c, i, m - 1)) {
				answer = (0ll + answer + dp (i + 1, c, k - 1, n, m) % MOD) % MOD;
			}
		}

		for (int i = c; i + 1 < m; i++) {
			if (qg.query(r, c, n - 1, i)) {
				answer = (0ll + answer + dp (r, i + 1, k - 1, n, m) % MOD) % MOD;
			}
		}

		return answer;
	}
	int ways(vector<string>& pizza, int k) {
		qg.build(pizza);
		memset (cache, -1, sizeof(cache));
		return dp (0, 0, k - 1, pizza.size(), pizza[0].size());
	}
};