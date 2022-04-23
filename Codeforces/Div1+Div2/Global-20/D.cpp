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

int T, N, A[mxN], B[mxN];

void solve()
{
    cin >> N;
    vector<int> cnt(N + 2, 0);
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
    	cin >> B[i];
    }

    int i = 1, j = 1;
    while(j <= N){
    	if(i > N){
    		if(j > 1 and B[j] == B[j - 1] and cnt[B[j]]){
    			cnt[B[j]] -= 1;
    			j += 1;
    		}else{
    			break;
    		}
    	}else{
    		if(A[i] == B[j]){
	    		i += 1, j += 1;
	    	}else{
	    		if(j > 1 and B[j] == B[j - 1] and cnt[B[j]]){
	    			cnt[B[j]] -= 1;
	    			j += 1;
	    		}else{
	    			cnt[A[i]] += 1;
	    			i += 1;
	    		}
	    	}
    	}
    }

    cout << (i == j and i == N + 1 ? "YES" : "NO") << '\n';
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