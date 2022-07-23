#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 5005;
const int INF = LLONG_MAX;

int N, M, X[mxN];

int dp(int index, int counter, vector<int> &CY, vector<vector<int>> &cache) {
	if (index > N) return 0;
	if (cache[index][counter] != -1) return cache[index][counter];

	int heads = dp(index + 1, counter + 1, CY, cache) + X[index] + CY[counter];
	int tails = dp(index + 1, 1, CY, cache);
	return cache[index][counter] = max(heads, tails);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> X[i];
	vector<int> CY(N + 2, 0);
	vector<vector<int>> cache(N + 2, vector<int>(N + 2, -1));
	for (int i = 1; i <= M; i++) {
		int X, Y;
		cin >> X >> Y;
		CY[X] = Y;
	}

	cout << dp(1, 1, CY, cache);

	return 0;
}