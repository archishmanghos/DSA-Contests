#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> getPrefixScores(vector<int> arr) {
	long sum = 0, prefSum = 0;
	int n = arr.size(), maxVal = 0;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		prefSum = prefSum + arr[i];
		sum = sum + prefSum;
		maxVal = max(maxVal, arr[i]);
		ans[i] = (maxVal * (i + 1)) + sum;
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
		cout << i << '\n';
	}
	cout << '\n';

	return 0;
}