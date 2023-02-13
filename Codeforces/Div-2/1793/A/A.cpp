#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int A, B; cin >> A >> B;
	int N, M; cin >> N >> M;
	int answer = (N / (M + 1)) * A * M + (N % (M + 1)) * min(A, B);
	cout << min(answer, min(N * A, N * B)) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}