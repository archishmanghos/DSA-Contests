#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int answer = a[0] + 1;
	for (int i = 1; i < n; i++) answer *= a[i];
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