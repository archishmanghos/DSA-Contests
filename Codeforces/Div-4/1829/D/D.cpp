#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, M; cin >> N >> M;

	if (M >= N) {
		cout << (M > N ? "No" : "Yes") << '\n';
		return;
	}

	if (N % 3 != 0) {
		cout << "No" << '\n';
		return;
	}

	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int x = q.front(); q.pop();
		int a = x / 3, b = 2 * x / 3;
		if (a == M or b == M) {
			cout << "Yes" << '\n';
			return;
		}

		if (a > M and a % 3 == 0) q.push(a);
		if (b > M and b % 3 == 0) q.push(b);
	}

	cout << "No" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}