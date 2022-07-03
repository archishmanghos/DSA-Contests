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

int T, N, M, K, A[mxN];

void solve() {
    
    cin >> N >> M >> K;
    vector<int> freq(N + 2, 0);
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	freq[A[i]] += 1;
    }
    
    int countLess = 0;
    for(int i = 0; i < K; i++){
    	if(freq[i] == 0){
    		cout << "NO" << '\n';
    		return;
    	}
    	countLess += freq[i];
    }

    int reqd = K;
    if(reqd <= M){
    	M -= reqd;
    	if(N - (reqd + freq[K]) >= M) cout << "YES" << '\n';
    	else cout << "NO" << '\n';
    }else{
    	cout << "NO" << '\n';
    }

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