#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumPartition(string s, int k) {
		int64_t ans = 1, num = 0, j = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (k < 10 and (s[i] - '0') > k) return -1;
			num += (s[i] - '0') * j;
			if (num > k) {
				ans += 1;
				num = (s[i] - '0');
				j = 1;
			}
			j *= 10;
		}

		return int(ans);
	}
};