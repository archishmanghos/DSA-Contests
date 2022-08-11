#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (int &i : arr) cin >> i;

	vector<int> cache(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		int maxElement = 0;
		for (int j = i; j < min(i + k, n); j++) {
			maxElement = max(maxElement, arr[j]);
			cache[i] = max(cache[i], cache[j + 1] + (j - i + 1) * maxElement);
		}
	}

	cout << cache[0];
	return 0;
}