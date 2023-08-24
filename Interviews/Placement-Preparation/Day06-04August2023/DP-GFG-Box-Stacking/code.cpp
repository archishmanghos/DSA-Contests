#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxHeight(int height[], int width[], int length[], int n) {

		int cache[100][4][4];
		memset(cache, -1, sizeof(cache));
		// height -> 1
		// width -> 2
		// length -> 3

		function<int(int, int, int)> dp = [&](int idx, int preL, int preW) {
			int &answer = cache[idx][preL][preW];
			if (answer != -1) return answer;

			answer = 0;
			if (preL == 0) {
				for (int i = 0; i < n; i++) {
					answer = max(answer, dp (i, 1, 2) + length[i]);
					answer = max(answer, dp (i, 2, 3) + height[i]);
					answer = max(answer, dp (i, 1, 3) + width[i]);
					answer = max(answer, dp (i, 2, 1) + length[i]);
					answer = max(answer, dp (i, 3, 2) + height[i]);
					answer = max(answer, dp (i, 3, 1) + width[i]);
				}
			} else {
				int l = (preL == 1 ? height[idx] : preL == 2 ? width[idx] : length[idx]);
				int w = (preW == 1 ? height[idx] : preW == 2 ? width[idx] : length[idx]);

				for (int i = 0; i < n; i++) {
					int cl = length[i], cw = width[i], ch = height[i];
					if (ch > l and cw > w) answer = max(answer, dp (i, 1, 2) + cl);
					if (cw > l and ch > w) answer = max(answer, dp (i, 2, 1) + cl);
					if (ch > l and cl > w) answer = max(answer, dp (i, 1, 3) + cw);
					if (cl > l and ch > w) answer = max(answer, dp (i, 3, 1) + cw);
					if (cw > l and cl > w) answer = max(answer, dp (i, 2, 3) + ch);
					if (cl > l and cw > w) answer = max(answer, dp (i, 3, 2) + ch);
				}
			}

			return answer;
		};

		return dp(0, 0, 0);
	}
};