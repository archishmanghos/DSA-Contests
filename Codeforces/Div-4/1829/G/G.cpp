#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	int layer;
	for (int i = 1; ; i++) {
		if (i * (i + 1) / 2 >= N) {
			layer = i;
			break;
		}
	}

	int answer = 0, a = N, b = N;
	for (int i = layer; i >= 1; i--) {
		answer += ((b * (b + 1) * (2 * b + 1)) - ((a - 1) * a * (2 * a - 1))) / 6;
		a = max(((i - 1) * (i - 2) / 2) + 1, a - i);
		b = min(i * (i - 1) / 2, b - i + 1);
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