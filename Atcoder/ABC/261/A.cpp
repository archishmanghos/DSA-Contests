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

vector<pair<int, int>> LR(2);

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	cin >> LR[0].first >> LR[0].second >> LR[1].first >> LR[1].second;
	sort(LR.begin(), LR.end());

	if (LR[0].second < LR[1].first) cout << 0;
	else if (LR[0].second <= LR[1].second)cout << LR[0].second - LR[1].first;
	else cout << LR[1].second - LR[1].first;

	return 0;
}