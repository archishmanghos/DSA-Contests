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
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    for(int i = -1; i <= 1; i++){
    	int B[N + 2];
    	for(int j = 1; j <= N; j++){
    		B[j] = A[j];
    	}

    	B[1] += i;
    	bool done = true;
    	for(int j = 2; j <= N; j++){
    		if(B[j] - B[j - 1] == 0){
    			B[j] += 1;
    		}else if(B[j] - B[j - 1] == 1){
    			continue;
    		}else if(B[j] - B[j - 1] == 2){
    			B[j] -= 1;
    		}else{
    			done = false;
    			break;
    		}
    	}

    	if(done){
    		cout << "YES" << '\n';
    		return;
    	}
    }

    cout << "NO" << "\n";
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