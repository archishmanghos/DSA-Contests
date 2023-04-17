#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S; cin >> S;
	cout << (S.size() > 10 ? (S[0] + to_string(S.size() - 2) + S.back()) : S) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}