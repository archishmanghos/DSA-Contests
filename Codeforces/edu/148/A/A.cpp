#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S; cin >> S;
	int N = S.size();

	char c = '0';
	for (int i = 1; i < N / 2; i++) {
		if (S[i] != S[0]) {
			c = S[i];
			break;
		}
	}

	cout << (c == '0' ? "NO" : "YES") << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}