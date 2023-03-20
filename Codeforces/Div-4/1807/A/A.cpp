#include <bits/stdc++.h>
#define int long long

void solve() {
	int A, B, C; std::cin >> A >> B >> C;
	if (A + B == C) std::cout << "+" << '\n';
	else std::cout << "-" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}