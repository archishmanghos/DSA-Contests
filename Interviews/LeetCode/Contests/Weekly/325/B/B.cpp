#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getAns(vector<vector<int>> &cnt, int n, int k) {
		bool ans = false;
		int n1 = cnt.size();
		if (n > n1) return 0;
		for (int i = 0; i <= n; i++) {
			bool ok = true;
			for (int j = 0; j < 3; j++) {
				int count = 0;
				if (i > 0) count += cnt[i - 1][j];
				if (n1 - (n - i) - 1 >= 0) count += cnt[n1 - 1][j] - cnt[n1 - (n - i) - 1][j];
				ok &= count >= k;
			}
			if (ok) {
				ans = true;
				break;
			}
		}

		return ans;
	}
	int takeCharacters(string s, int k) {
		int n = s.size();
		vector<vector<int>> cnt(n, vector<int>(3, 0));
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				for (int j = 0; j < 3; j++) {
					cnt[i][j] += cnt[i - 1][j];
				}
			}
			cnt[i][s[i] - 'a'] += 1;
		}

		int ans = 1e9, low = 1, high = n;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int gAns = getAns(cnt, mid, k);
			if (!gAns) low = mid + 1;
			else {
				ans = mid;
				high = mid - 1;
			}
		}

		return (ans == 1e9 ? -1 : ans);
	}
};