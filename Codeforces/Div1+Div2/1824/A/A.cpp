#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S; cin >> S;
	sort(S.begin(), S.end());
	if (S[0] == S.back()) cout << -1 << '\n';
	else cout << S.size() - 1 << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}