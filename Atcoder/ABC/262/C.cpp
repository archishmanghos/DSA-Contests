#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {

	int N; cin >> N;
	vector<int> A(N + 1), index(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		index[i] = A[i];
	}

	int ans = 0, inPlace = 0;
	for (int i = N; i >= 1; i--) {
		if (A[i] == i) {
			ans += inPlace;
			inPlace += 1;
		} else {
			if (i > index[i]) {
				if (index[index[i]] == i) ans += 1;
			}
		}
	}

	cout << ans;

	return 0;
}