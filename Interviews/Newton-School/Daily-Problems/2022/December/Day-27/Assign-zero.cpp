#include <bits/stdc++.h>
using namespace std;

int A[6];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(A, -1, sizeof(A));
	for (int i = 1; i <= 5; i++) {
		int X; cin >> X; A[X] += 1;
	}

	for (int i = 1; i <= 5; i++) {
		if (A[i] == -1) cout << i;
	}

	return 0;
}