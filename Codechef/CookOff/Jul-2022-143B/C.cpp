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

int T, N, L, R;

void solve() {
    
    cin >> N;
    vector<bool> claimsToBeThief(N + 5, false);
    vector<int> otherClaimsThief(N + 5, 0);
    for(int i = 1; i <= N; i++){
    	cin >> L >> R;
    	otherClaimsThief[L] += 1;
    	otherClaimsThief[R + 1] -= 1;
    	if(i >= L and i <= R) claimsToBeThief[i] = true;
    }

    for(int i = 2; i <= N; i++) otherClaimsThief[i] += otherClaimsThief[i - 1];

    vector<int> ans;
    for(int i = 1; i <= N; i++){
    	if(otherClaimsThief[i] == N - 1 and !claimsToBeThief[i]) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for(int i : ans) cout << i << '\n';
    
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