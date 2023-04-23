#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	int gcdd = A[0];
	for (int i : A) gcdd = __gcd(gcdd, i);
	if (gcdd > 1) {
		cout << -1;
		return 0;
	}

	int one = 0;
	for (int i : A) one += i == 1;
	if (one > 0) {
		cout << (N - one);
		return 0;
	}

	int minL = 1e9 + 7;
	for (int i = 0; i + 1 < N; i++) {
		int gcddd = A[i];
		for (int j = i; j < N; j++) {
			gcddd = __gcd(gcddd, A[j]);
			if (gcddd == 1) {
				minL = min(minL, (j - i + 1));
				break;
			}
		}
	}

	cout << (N + minL - 2);
	return 0;
}