#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K; cin >> N >> K;
	vector<vector<int>> A(N, vector<int>(2));
	for (int i = 0; i < N; i++) cin >> A[i][0] >> A[i][1];
	sort(A.begin(), A.end(), [&](vector<int> &a, vector<int> &b) {
		if (a[0] != b[0]) return a[0] > b[0];
		return a[1] < b[1];
	});

	int startRank = 1, endRank = 1, score = A[0][0], penalty = A[0][1];
	for (int i = 1; i < N; i++) {
		if (score != A[i][0] or penalty != A[i][1]) {
			if (K >= startRank and K <= endRank) {
				cout << (endRank - startRank + 1);
				return 0;
			}
			startRank = endRank + 1;
			endRank = startRank;
			score = A[i][0], penalty = A[i][1];
		} else {
			endRank++;
		}
	}

	cout << (endRank - startRank + 1);
	return 0;
}