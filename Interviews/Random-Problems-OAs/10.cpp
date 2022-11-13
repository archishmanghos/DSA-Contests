#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

vector<int> getPrefixScores(vector<int> arr) {
	long sum = 0, prefSum = 0;
	int n = arr.size(), mod = 1e9 + 7, maxVal = 0;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		prefSum = (prefSum + arr[i]) % mod;
		sum = (sum + prefSum) % mod;
		maxVal = max(maxVal, arr[i]);
		ans[i] = ((maxVal * (i + 1)) % mod + sum) % mod;
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> ans = getPrefixScores(arr);
	for (int i : ans) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}