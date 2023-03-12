#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int A, B; cin >> A >> B;
	A = abs(A);
	B = abs(B);
	if (A == B) cout << (A * 2) << '\n';
	else if (A < B) cout << ((A * 2) + ((B - A) * 2 - 1)) << '\n';
	else cout << ((B * 2) + ((A - B) * 2 - 1)) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}