#include <bits/stdc++.h>
#define i64 int64_t
using namespace std;

int32_t main() {
	ofstream fout ("haybales.out");
	ifstream fin ("haybales.in");

	int N, Q; fin >> N >> Q;
	int A[N]; for (int i = 0; i < N; i++) fin >> A[i];

	std::sort(A, A + N);
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

	auto ub = [](int val, int arr[], int n) {
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

	while (Q--) {
		int L, R; fin >> L >> R;
		int idx1 = lb(L, A, N);
		if (idx1 == -1) {
			fout << 0 << '\n';
			continue;
		}

		int answer = N - idx1;
		int idx2 = ub(R, A, N);
		if (idx2 != -1) answer -= N - idx2;
		fout << answer << '\n';
	}

	return 0;
}