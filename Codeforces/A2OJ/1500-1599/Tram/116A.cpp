#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int A[N], B[N];
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

	int low = 0, high = 1e7, answer;
	while (low <= high) {
		int mid = (low + high) / 2;
		auto f = [&]() -> bool {
			int passengers = 0;
			for (int i = 0; i < N - 1; i++) {
				passengers -= (A[i] - B[i]);
				if (passengers > mid) return false;
			}
			return true;
		};

		if (f()) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	cout << answer;
	return 0;
}