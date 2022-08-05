#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<int> prefLis(n, 1), suffLis(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				prefLis[i] = max(prefLis[i], 1 + prefLis[j]);
			}
		}
	}

	int maxBitonicLength = 1;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i]) {
				suffLis[i] = max(suffLis[i], 1 + suffLis[j]);
			}
		}
		if (arr[i] != arr[i + 1]) {
			maxBitonicLength = max(maxBitonicLength, prefLis[i] + suffLis[i + 1]);
		}
	}

	cout << maxBitonicLength;
	return 0;
}