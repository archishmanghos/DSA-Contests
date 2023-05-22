#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; string S; cin >> N >> S;
	set<string> s;
	for (int i = 1; i < N; i++) {
		string X = to_string(S[i - 1]);
		X += S[i];
		s.insert(X);
	}

	cout << s.size() << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}