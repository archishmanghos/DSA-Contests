#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int pref[N];
	pref[0] = A[0];
	for (int i = 1; i < N; i++) pref[i] = A[i] + pref[i - 1];

	while (M--) {
		auto ub = [](int val, int arr[], int n) {
			int answer = n, low = 0, high = n - 1;
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

		int X; cin >> X;
		int idx = ub(X, A, N);
		int leftActualSum = (idx - 1 >= 0 ? pref[idx - 1] : 0);
		int rightActualSum = pref[N - 1] - (idx - 1 >= 0 ? pref[idx - 1] : 0);
		int leftToBeSum = idx * X;
		int rightToBeSum = (N - idx) * X;

		cout << (leftToBeSum - leftActualSum) + (rightActualSum - rightToBeSum) << ' ';
	}
	return 0;
}