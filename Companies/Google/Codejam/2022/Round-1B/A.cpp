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
deque<int> dq;

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++){
    	cin >> A;
    	dq.push_back(A);
    }

    int minNow = -1, ans = 0;
    while(!dq.empty()){
    	if(dq.front() > dq.back()){
    		if(dq.back() >= minNow){
    			ans += 1;
    			minNow = dq.back();
    		}
    		dq.pop_back();
    	}else{
    		if(dq.front() >= minNow){
    			ans += 1;
    			minNow = dq.front();
    		}
    		dq.pop_front();
    	}
    }

    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}