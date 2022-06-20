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

int T, N;
string S;

void solve() {
    
    cin >> N >> S;
    vector<int> segments;

 	int count = 1;
    for(int i = 1; i < N; i++){
    	if(S[i] != S[i - 1]) {
    		segments.push_back(count);
    		count = 1;
    	}else count += 1;
    }
    segments.push_back(count);

    int oddIndex1 = -1, ans = 0;
    for(int i = 0; i < segments.size(); i++){
    	if(segments[i] % 2){
    		if(oddIndex1 != -1) ans += (i - oddIndex1 - 1) + 1, oddIndex1 = -1;
    		else oddIndex1 = i;
    	}
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}