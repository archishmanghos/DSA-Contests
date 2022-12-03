#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t A, B = 0; cin >> A;
	for (int i = 63; i >= 2; i--) {
		if ((A >> i) & 1LL) {
			B |= (1LL << i);
		}
	}

	if (!((A >> 1) & 1)) {
		B ^= (1 << 1);
	}
	if ((A >> 0) & 1) {
		B ^= (1 << 0);
	}

	cout << B;
	return 0;
}