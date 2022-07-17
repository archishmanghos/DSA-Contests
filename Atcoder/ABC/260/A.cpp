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

string S;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	cin >> S;
	sort(S.begin(), S.end());
	if (S[0] == S[1] and S[1] != S[2]) cout << S[2];
	else if (S[0] != S[1] and S[1] == S[2]) cout << S[0];
	else if (S[0] == S[2]) cout << -1;
	else cout << S[0];

	return 0;
}