#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	int A[N + 2]; for (int i = 1; i <= N; i++) cin >> A[i];

	sort(A + 1, A + N + 1);
	int pref[N + 2], suff[N + 2];
	memset(pref, 0, sizeof(pref));
	memset(suff, 0, sizeof(suff));
	pref[1] = A[1];
	suff[N] = A[N];
	for (int i = 2; i <= N; i++) pref[i] = A[i] + pref[i - 1];
	for (int i = N - 1; i >= 1; i--) suff[i] = A[i] + suff[i + 1];

	int answer = 0, totSum = accumulate(A + 1, A + N + 1, 0ll);
	for (int i = 0; i <= K; i++) {
		int left = i, right = K - i;
		int sum = pref[2 * left] + suff[N - right + 1];
		answer = max(answer, totSum - sum);
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