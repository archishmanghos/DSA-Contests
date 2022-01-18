#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N;
    string S, T;
    cin >> N >> S >> T;

    int placesMatching = 0, placesNotMatching = 0, cntMatching[2] = {0}, cntNotMatching[2] = {0};
    for(int i = 0; i < N; i++){
    	if(S[i] != T[i]){
    		placesNotMatching += 1;
    		cntNotMatching[(S[i] - '0')] += 1;
    	}else{
    		placesMatching += 1;
    		cntMatching[(S[i] - '0')] += 1;
    	}
    }

    int ans = INF;
    if(placesMatching % 2){
    	if(cntMatching[1] == cntMatching[0] + 1){
    		ans = min(ans, placesMatching);
    	}
    }

    if(placesNotMatching % 2 == 0){
    	if(cntNotMatching[1] == cntNotMatching[0]){
    		ans = min(ans, placesNotMatching);
    	}
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}