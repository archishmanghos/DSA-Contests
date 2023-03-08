#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K; std::cin >> N >> K;
	int A[N + 2]; for (int i = 1; i <= N; i++) std::cin >> A[i];

	std::sort(A + 1, A + N + 1);
	i64 low = A[(N + 1) / 2], high = *(std::max_element(A + 1, A + N + 1)) + K, answer = -1;

	while (low <= high) {
		i64 mid = low + (high - low) / 2;
		auto f = [&]() {
			i64 operationReqd = 0;
			for (int i = (N + 1) / 2; i <= N; i++) {
				operationReqd += std::max(0ll, 0ll + mid - A[i]);
			}

			return operationReqd <= K;
		};

		if (f()) {
			answer = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	std::cout << answer;
	return 0;
}