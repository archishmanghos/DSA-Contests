#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; std::cin >> N >> M;
	int A[N]; for (int i = 0; i < N; i++) std::cin >> A[i];
	int B[M]; for (int i = 0; i < M; i++) std::cin >> B[i];

	std::sort(A, A + N);
	std::sort(B, B + M);

	auto lb = [](int val, int arr[], int n) {
		int answer = -1, low = 0, high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] >= val) {
				answer = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return answer;
	};

	i64 low = 0, high = 1e18, answer = -1;
	while (low <= high) {
		i64 mid = low + (high - low) / 2;
		auto f = [&]() {
			for (int i = 0; i < N; i++) {
				int idx1 = lb(A[i], B, M);
				int idx2 = (idx1 == -1 ? M - 1 : idx1 - 1);

				i64 minDist = 1e18;
				if (idx1 == -1) minDist = 0l + A[i] - B[idx2];
				else if (idx2 == -1) minDist = 0l + B[idx1] - A[i];
				else minDist = std::min(B[idx1] - A[i], A[i] - B[idx2]);

				if (minDist > mid) return false;
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

	std::cout << answer;
	return 0;
}