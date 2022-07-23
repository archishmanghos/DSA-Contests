#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int N;
string S;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	cin >> N;
	map<string, int> mp;
	while (N--) {
		cin >> S;
		if (mp.find(S) != mp.end()) {
			cout << S << '(' << mp[S] << ')' << '\n';
		} else {
			cout << S << '\n';
		}
		mp[S] += 1;
	}

	return 0;
}