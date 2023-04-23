#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A1, A2, K1, K2, N; cin >> A1 >> A2 >> K1 >> K2 >> N;
	if (K1 > K2) {
		swap(K1, K2);
		swap(A1, A2);
	}

	int N1 = N;
	N1 -= A1 * (K1 - 1) + A2 * (K2 - 1);
	cout << max(0, N1) << ' ';

	int maximum = min(A1, N / K1);
	N -= maximum * K1;
	maximum += min(A2, N / K2);

	cout << maximum;
	return 0;
}
