#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A;

void solve() {
    set<int> s;
    cin >> N;
    int cnt = 0;
    bool zero = false;
    for(int i = 1; i <= N; i++){
    	cin >> A;
    	zero |= A == 0;
    	if(A != 0){
    		cnt += 1;
    		s.insert(A);
    	}
    }

    if(zero){
    	cout << cnt << '\n';
    }else{
    	if((int)s.size() == N){
    		cout << N + 1 << '\n';
    	}else{
    		cout << N << '\n';
    	}
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