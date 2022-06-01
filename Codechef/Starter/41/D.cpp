#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];

	// https://www.geeksforgeeks.org/longest-subarray-consisting-of-unique-elements-from-an-array/
	unordered_map<int, int> index;
    int ans = 0, finalAns = INF;
    for (int i = 0, j = 0; i < N; i++){
        j = max(index[A[i]], j);
        ans = max(ans, i - j + 1);
        int left = j, right = N - 1 - i;
        finalAns = min(finalAns, left + right + min(left, right));
        index[A[i]] = i + 1;
    }
	
	cout << finalAns << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}