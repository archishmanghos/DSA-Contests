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
	for(int i = 1; i <= N; i++) cin >> A[i];

	for(int i = 0; i < 31; i++){
		int curSum = 0, start = 1, preSum = 0;
		vector<pair<int, int>> ans;
		for(int j = 1; j <= N; j++){
			curSum += A[j];
			if(curSum & (1 << i)){
				ans.push_back({start, j});
				preSum = curSum;
				curSum = 0, start = j + 1;
			}
		}

		if(ans.size() > 0){
			if((curSum + preSum) & (1 << i)) {
				start = ans.back().first;
				ans.pop_back();
				ans.push_back({start, N});
			}
		}

		if(ans.size() > 1 and ans.back().second == N){
			cout << "YES" << '\n';
			cout << ans.size() << '\n';
			for(auto i : ans) cout << i.first << ' ' << i.second << '\n';
			return;
		}
	}

	cout << "NO" << '\n';
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