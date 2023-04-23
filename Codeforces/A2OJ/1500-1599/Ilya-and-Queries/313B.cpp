#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string S; cin >> S;
	int N = S.size(), M; cin >> M;

	int pref[N] = {0}; pref[0] = S[0] == S[1];
	for (int i = 1; i + 1 < N; i++) pref[i] = (S[i] == S[i + 1]) + pref[i - 1];
	pref[N - 1] = pref[N - 2];

	while (M--) {
		int L, R; cin >> L >> R; L--, R--;
		cout << (pref[R - 1] - (L > 0 ? pref[L - 1] : 0)) << '\n';
	}
	return 0;
}