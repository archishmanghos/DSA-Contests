#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	sort(A, A + N);
	int answer = 0, i = 0, j = N - 1;
	while (i < j) answer += A[j--] - A[i++];
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