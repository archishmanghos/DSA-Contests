#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	int oneone = 1e15, onezero = 1e15, zeroone = 1e15;
	for (int i = 1; i <= N; i++) {
		int M; string S; cin >> M >> S;
		if (S == "10") onezero = min(onezero, M);
		if (S == "01") zeroone = min(zeroone, M);
		if (S == "11") oneone = min(oneone, M);
	}

	int answer = min(onezero + zeroone, oneone);
	cout << (answer == 1e15 ? -1 : answer) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}