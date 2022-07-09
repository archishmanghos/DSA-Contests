#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int s, t, q;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

	cin >> s >> t >> q;
	set<int> occupied;
	for (int i = 1; i <= t; i++) {
		int x;
		cin >> x;
		occupied.insert(x);
	}

	while (q--) {
		int x; cin >> x;
		if (occupied.find(x) != occupied.end()) cout << "N" << '\n';
		else cout << "Y" << '\n';
	}

    return 0;
}