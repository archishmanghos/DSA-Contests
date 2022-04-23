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

int T, N, A[mxN];

void solve()
{
    cin >> N;
    int cntEqualStart = 0, cntEqualEnd = 0;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	if(i > 1){
    		if(A[i] == A[i - 1]){
    			if(!cntEqualStart){
    				cntEqualStart = i - 1;
    			}
    			cntEqualEnd = i;
    		}
    	}
    }

    if(cntEqualStart == 0){
    	cout << 0 << '\n';
    	return;
    }

    bool allSame = true;
    for(int i = cntEqualStart; i <= cntEqualEnd; i++){
    	allSame &= A[i] == A[cntEqualStart];
    }

    if(allSame){
    	int stretch = (cntEqualEnd - cntEqualStart + 1);
    	if(stretch == 2){
    		cout << 0 << '\n';
    	}else if(stretch <= 4){
    		cout << 1 << '\n';
    	}else{
    		cout << stretch - 3 << '\n';
    	}
    }else{
    	cout << max(0LL, (cntEqualEnd - cntEqualStart + 1) - 3) << '\n';
    }
}

int32_t main()
{
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