#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);

	int low = 1, high = N, answer;
	while (low <= high) {
		int mid = (low + high) / 2;
		auto f = [&]() {
			for (int i = 0; i < mid; i++) {
				for (int j = i; j < N; j += mid) {
					if ((j - i) / mid > A[j]) {
						return false;
					}
				}
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