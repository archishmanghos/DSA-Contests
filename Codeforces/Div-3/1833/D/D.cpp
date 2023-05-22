#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	auto getPermutation = [&](int l, int r) {
		vector<int> temp(N);
		int j = 0;
		for (int i = r + 1; i < N; i++) temp[j++] = A[i];
		for (int i = r; i >= l; i--) temp[j++] = A[i];
		for (int i = 0; i < l; i++) temp[j++] = A[i];

		return temp;
	};

	auto comparePermutation = [&](vector<int> &a, vector<int> &b) {
		for (int i = 0; i < N; i++) {
			if (a[i] > b[i]) return 1;
			if (a[i] < b[i]) return -1;
		}

		return 0;
	};


	vector<int> answer = getPermutation(0, 0);
	vector<int> temp = getPermutation(0, N - 1);
	if (comparePermutation(answer, temp) == -1) answer = temp;
	temp = getPermutation(N - 1, N - 1);
	if (comparePermutation(answer, temp) == -1) answer = temp;

	if (N > 1) {
		int maxInd = 0, maxInd2 = 1;
		for (int i = 0; i < N; i++) {
			if (A[i] == N) maxInd = i;
			if (A[i] == N - 1) maxInd2 = i;
		}

		if (maxInd == 0) swap(maxInd, maxInd2);
		for (int i = 0; i < maxInd; i++) {
			temp = getPermutation(i, maxInd - 1);
			if (comparePermutation(answer, temp) == -1) answer = temp;
		}
	}

	for (int i = 0; i < N; i++) cout << answer[i] << ' ';
	cout << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}