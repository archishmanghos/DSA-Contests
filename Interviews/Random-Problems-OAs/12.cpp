#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int highJump (int N, vector<int> A) {
	vector<int> prefSum(10005, 0);
	int maxVal = A[0];
	for (int i = 1; i < N; i++) {
		int l = min(A[i - 1], A[i]);
		int r = max(A[i - 1], A[i]);
		prefSum[l] += 1;
		prefSum[r + 1] -= 1;
		maxVal = max(maxVal, A[i]);
	}

	vector<int> ans = {0, -1};
	for (int i = 1; i <= maxVal; i++) {
		prefSum[i] += prefSum[i - 1];
		if (prefSum[i] > ans[0]) {
			ans = {prefSum[i], i};
		}
	}

	return ans[1];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << highJump(n, a);
	return 0;
}