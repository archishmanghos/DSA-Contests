#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long int distinctColoring(int N, int r[], int g[], int b[]) {
		int64_t cache[50050][3];
		memset (cache, -1, sizeof(cache));

		auto dp = [&](int idx, int lastColour, auto && dp) {
			if (idx < 0) return 0l;
			int64_t &answer = cache[idx][lastColour];
			if (answer != -1) return answer;

			int64_t paintRed, paintGreen, paintBlue;
			paintRed = paintGreen = paintBlue = 1e18;
			if (idx == N - 1) {
				paintRed = dp (idx - 1, 0, dp) + r[N - 1];
				paintGreen = dp (idx - 1, 1, dp) + g[N - 1];
				paintBlue = dp (idx - 1, 2, dp) + b[N - 1];
			} else {
				if (lastColour == 0) {
					paintGreen = dp (idx - 1, 1, dp) + g[idx];
					paintBlue = dp (idx - 1, 2, dp) + b[idx];
				} else if (lastColour == 1) {
					paintRed = dp (idx - 1, 0, dp) + r[idx];
					paintBlue = dp (idx - 1, 2, dp) + b[idx];
				} else {
					paintRed = dp (idx - 1, 0, dp) + r[idx];
					paintGreen = dp (idx - 1, 1, dp) + g[idx];
				}
			}

			answer = min (paintRed, min (paintGreen, paintBlue));
			return answer;
		};

		return dp (N - 1, 0, dp);
	}
};