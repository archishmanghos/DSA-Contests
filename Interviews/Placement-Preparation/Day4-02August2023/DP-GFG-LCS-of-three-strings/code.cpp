#include <bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
	int cache[20][20][20];
	memset (cache, -1, sizeof(cache));
	function<int(int, int, int)> dp = [&](int idx1, int idx2, int idx3) {
		if (idx1 == n1 or idx2 == n2 or idx3 == n3) return 0;
		int &answer = cache[idx1][idx2][idx3];
		if (answer != -1) return answer;

		answer = 0;
		if (A[idx1] == B[idx2] and B[idx2] == C[idx3]) {
			answer = dp (idx1 + 1, idx2 + 1, idx3 + 1) + 1;
		} else {
			answer = dp (idx1 + 1, idx2, idx3);
			answer = max (answer, dp (idx1 + 1, idx2 + 1, idx3));
			answer = max (answer, dp (idx1 + 1, idx2, idx3 + 1));
			answer = max (answer, dp (idx1, idx2 + 1, idx3));
			answer = max (answer, dp (idx1, idx2 + 1, idx3 + 1));
			answer = max (answer, dp (idx1, idx2, idx3 + 1));
		}

		return answer;
	};

	return dp (0, 0, 0);
}