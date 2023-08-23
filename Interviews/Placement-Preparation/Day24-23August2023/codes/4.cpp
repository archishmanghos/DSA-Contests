#include <bits/stdc++.h>
using namespace std;

int cache[102][102][102];
int dp(int idx, int sum, int arrIdx, vector<int> &a, int totSum) {
	if (idx < 0) {
		return abs(2 * sum - totSum);
	}
	if (arrIdx == a.size()) return 1e9;
	int &answer = cache[idx][sum][arrIdx];
	if (answer != -1) return answer;

	answer = dp(idx, sum, arrIdx + 1, a, totSum);
	answer = min(answer, dp(idx - 1, sum + a[arrIdx], arrIdx + 1, a, totSum));
	return answer;
}

int evenOddArrangement(int n, vector<int> & a) {
	int even = (n + 1) / 2, totSum = accumulate(a.begin(), a.end(), 0);
	memset(cache, -1, sizeof(cache));
	return dp(even - 1, 0, 0, a, totSum);
}