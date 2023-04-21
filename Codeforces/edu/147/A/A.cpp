#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	string S; cin >> S;
	int answer = 1;
	for (int i = 1; i < S.size(); i++) answer *= (S[i] == '?' ? 10 : 1);

	if (S[0] == '0') {
		cout << 0 << '\n';
		return;
	}

	if (S[0] == '?') cout << answer * 9 << '\n';
	else cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}