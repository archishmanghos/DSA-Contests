#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int M, N; cin >> M >> N;
	int A[N][3];
	for (int i = 0; i < N; i++) cin >> A[i][0] >> A[i][1] >> A[i][2];

	int answer = -1, low = 0, high = 1e8;
	vector<int> ans;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		vector<int> temp(N);
		auto f = [&]() {
			int M1 = M;
			for (int i = 0; i < N; i++) {
				for (int j = M1; j > 0; j--) {
					int timeReq = j * A[i][0] + (((j + A[i][1] - 1) / A[i][1]) - 1) * A[i][2];
					if (timeReq <= mid) {
						temp[i] = j;
						M1 -= j;
						break;
					}
				}
			}

			return !M1;
		};

		if (f()) {
			answer = mid;
			ans = temp;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	cout << answer << '\n';
	for (int i : ans) cout << i << ' ';
	return 0;
}