#include <bits/stdc++.h>
using namespace std;

void solve() {
	int A; cin >> A;
	if (360 % (180 - A) == 0) cout << "YES";
	else cout << "NO";
	cout << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}