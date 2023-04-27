#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A, B, C;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x > 0) A.push_back(x);
		if (x < 0) B.push_back(x);
		C.push_back(x);
	}

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());
	sort(C.begin(), C.end());

	int answer = -1e18 + 7;
	if (A.size() > 1) answer = A[0] * A[1];
	if (B.size() > 1) answer = max(answer, B[0] * B[1]);
	answer = max(answer, C[0] * C[1]);

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