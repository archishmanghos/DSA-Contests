#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, Q; cin >> N >> Q;
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

	sort(A.begin(), A.end());
	while (Q--) {
		int K; cin >> K;
		vector<int> temp = A;
		int n = N;
		if (K >= N) n -= (K % 2 != N % 2);

		int j = K;
		for (int i = 0; i < min(n, K); i++) temp[i] += j--;

		sort(temp.begin(), temp.end());
		if (K < N) {
			cout << temp[0] << ' ';
			continue;
		}
		for (int i = N - 1; i > 0; i--) {
			int steps = min((temp[i] - temp[i - 1]) * (N - i) * 2, j);
			temp[i] -= (steps + (N - i) * 2 - 1) / (2 * (N - i));
			j -= steps;
		}

		sort(temp.begin(), temp.end());
		int rem = temp[0] - (((j / 2) + N - 1) / N);
		cout << rem << ' ';
	}
	return 0;
}