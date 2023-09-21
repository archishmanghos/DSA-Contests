#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int answer = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char c; cin >> c;
			int pointi = i < 5 ? i + 1 : 5 - (i % 5);
			int pointj = j < 5 ? j + 1 : 5 - (j % 5);
			if (c == 'X') answer += min(pointi, pointj);

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