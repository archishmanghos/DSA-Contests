#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<std::vector<int>> idx(N);
	for (int i = 0; i < N; i++) {
		int A; std::cin >> A;
		idx[A - 1].push_back(i);
	}

	auto lb = [](int val, std::vector<int> &arr, int n) {
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

	auto ub = [](int val, std::vector<int> &arr, int n) {
		int answer = -1, low = 0, high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] > val) {
				answer = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return answer;
	};

	int Q; std::cin >> Q;
	while (Q--) {
		int L, R, X; std::cin >> L >> R >> X;
		X--, L--, R--;
		int n = idx[X].size();
		int idx1 = lb(L, idx[X], n);
		if (idx1 == -1) {
			std::cout << 0 << '\n';
			continue;
		}

		int idx2 = ub(R, idx[X], n);
		if (idx2 == -1) std::cout << (n - idx1) << '\n';
		else std::cout << (idx2 - idx1) << '\n';
	}

	return 0;
}