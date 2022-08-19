#include <bits/stdc++.h>

vector<int> findTrainStation(int n, vector<int> v, int q, vector<int> query) {
	vector<int> prefSum(n, 0), suffSum(n, 0);
	prefSum[0] = v[0], suffSum[n - 1] = v[n - 1];
	for (int i = 1; i < n; i++) prefSum[i] += prefSum[i - 1] + v[i];
	for (int i = n - 2; i >= 0; i--) suffSum[i] += suffSum[i + 1] + v[i];

	int minutes = prefSum[n - 1];
	reverse(suffSum.begin(), suffSum.end());

	for (int i : prefSum) cout << i << ' ';
	cout << '\n';
	for (int i : suffSum) cout << i << ' ';
	cout << '\n';

	vector<int> ans(q);
	for (int i = 0; i < q; i++) {
		int turn = query[i] / minutes;
		int rem = query[i] % minutes;
		if (turn % 2 == 0) {
			auto it = upper_bound(prefSum.begin(), prefSum.end(), rem);
			if (it == prefSum.end()) ans[i] = n;
			else {
				int station = it - prefSum.begin();
				ans[i] = station + 1;
			}
		} else {
			auto it = upper_bound(suffSum.begin(), suffSum.end(), rem);
			if (it == suffSum.end()) ans[i] = 1;
			else {
				int station = it - suffSum.begin();
				ans[i] = n - station;
			}
		}
	}

	return ans;
}