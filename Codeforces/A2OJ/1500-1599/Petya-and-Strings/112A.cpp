#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string A, B; cin >> A >> B;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] >= 'A' and A[i] <= 'Z') A[i] ^= ' ';
		if (B[i] >= 'A' and B[i] <= 'Z') B[i] ^= ' ';
	}

	for (int i = 0; i < A.size(); i++) {
		if (A[i] < B[i]) {
			cout << -1;
			return 0;
		}
		if (A[i] > B[i]) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}