#include <bits/stdc++.h>
using namespace std;

int maxSumBS(int arr[] , int n ) {
	int cache[1005][1005][2];
	memset(cache, -1, sizeof(cache));
	function<int(int, int, int)> dp = [&](int preIdx, int idx, int incr) {
		if (idx == n + 1) return 0;
		int &answer = cache[preIdx][idx][incr];
		if (answer != -1) return answer;

		answer = dp (preIdx, idx + 1, incr);
		if (preIdx == 0) {
			answer = max (answer, dp (idx, idx + 1, incr) + arr[idx - 1]);
		} else {
			if (arr[idx - 1] > arr[preIdx - 1]) {
				if (incr) answer = max (answer, dp (idx, idx + 1, incr) + arr[idx - 1]);
			} else if (arr[idx - 1] < arr[preIdx - 1]) {
				if (incr) answer = max (answer, dp (idx, idx + 1, !incr) + arr[idx - 1]);
				else answer = max (answer, dp (idx, idx + 1, incr) + arr[idx - 1]);
			}
		}

		return answer;
	};

	return dp (0, 1, 1);
}