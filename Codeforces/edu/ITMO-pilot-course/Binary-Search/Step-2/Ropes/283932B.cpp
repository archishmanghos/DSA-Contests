#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K; cin >> N >> K;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	double low = 0, high = 1e9, answer = -1;

	while (high - low > (1e-6)) {
		double mid = (low + high) / 2;
		auto f = [&]() {
			int pieces = 0;
			for (int i = 0; i < N; i++) pieces += (A[i] / mid);
			return pieces >= K;
		};

		if (f()) {
			answer = mid;
			low = mid;
		} else {
			high = mid;
		}
	}

	cout << fixed << setprecision(9) << answer;
	return 0;
}