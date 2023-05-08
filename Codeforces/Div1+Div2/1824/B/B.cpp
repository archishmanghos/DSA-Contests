#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	int A[N * M]; for (int i = 0; i < N * M; i++) cin >> A[i];

	sort(A, A + N * M);

	auto getAns = [&](int betterDiff, int diff, int k1, int k2) {
		int answer = betterDiff * (k1 - 1) + diff * (k2 - 1);
		answer += ((N * M) - (k1 + k2 - 1)) * betterDiff;
		return answer;
	};

	int answer = 0;
	int betterDiff1 = A[N * M - 1] - A[0], diff1 = A[N * M - 2] - A[0];
	int betterDiff2 = A[N * M - 1] - A[0], diff2 = A[N * M - 1] - A[1];
	if (N > M) {
		answer = max(answer, getAns(betterDiff1, diff1, N, M));
		answer = max(answer, getAns(betterDiff2, diff2, N, M));

	} else {
		answer = max(answer, getAns(betterDiff1, diff1, M, N));
		answer = max(answer, getAns(betterDiff2, diff2, M, N));
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}