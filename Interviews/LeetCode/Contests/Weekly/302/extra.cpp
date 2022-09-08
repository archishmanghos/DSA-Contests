#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;



int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	int ans = 0, j = 10;
	for (int i = 1; i <= 20; i++) {
		ans += j;
		j <<= 1;
	}

	cout << ans;

	return 0;
}