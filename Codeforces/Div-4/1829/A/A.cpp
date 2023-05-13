#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S, T = "codeforces"; cin >> S;
	int answer = 0;
	for (int i = 0; i < 10; i++) answer += S[i] != T[i];
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