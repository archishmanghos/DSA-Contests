#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

// #define int long long
using namespace std;

int countAnalogousArrays(vector<int> &consecutiveDifference, int lowerBound, int upperBound) {
	int n = consecutiveDifference.size();
	long maxPositiveSum = 0, curPositiveSum = 0, curNegativeSum = 0, maxNegativeSum = 0;
	for (int i = 0; i < n; i++) {
		curNegativeSum += consecutiveDifference[i];
		curPositiveSum += consecutiveDifference[i];

		maxPositiveSum = max(maxPositiveSum, curPositiveSum);
		maxNegativeSum = min(maxNegativeSum, curNegativeSum);
	}

	long ub = upperBound + maxNegativeSum, lb = lowerBound + maxPositiveSum;
	return max(ub - lb + 1, 0l);
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int lb, ub; cin >> lb >> ub;

	cout << countAnalogousArrays(a, lb, ub);
	return 0;
}