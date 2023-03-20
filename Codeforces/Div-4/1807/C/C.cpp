#include <bits/stdc++.h>
#define int long long

void solve() {
	int N;
	std::string S;
	std::cin >> N >> S;

	for (char c = 'a'; c <= 'z'; c++) {
		int parity = -1;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == c) {
				if (parity == -1 or parity == (i % 2)) {
					parity = i % 2;
					continue;
				}
				std::cout << "NO" << '\n';
				return;
			}
		}
	}

	std::cout << "YES" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}