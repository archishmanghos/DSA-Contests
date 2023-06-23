#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	int answer = 0;
	while (N) {
		answer += N;
		N >>= 1ll;
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