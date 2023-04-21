#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	string S; cin >> S;
	int N = S.size();

	int answer = 1e9;
	for (char c = 'a'; c <= 'z'; c++) {
		set<int> pos;
		bool ok = false;
		for (int i = 0; i < N; i++) {
			ok |= (S[i] == c);
			if (S[i] != c) pos.insert(i);
		}

		if (ok) {
			int moves = 0;
			while (pos.size() > 0) {
				int pre = -2, erased = 0;
				vector<int> remaining;
				for (int i : pos) {
					if (i - 1 > pre) {
						erased++;
						pre = i;
					} else {
						remaining.push_back(i - erased);
					}
				}

				moves++;
				pos.clear();
				for (int i : remaining) {
					pos.insert(i);
				}
			}

			answer = min(answer, moves);
		}
	}

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