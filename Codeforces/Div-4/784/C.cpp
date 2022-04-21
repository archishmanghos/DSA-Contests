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
    set<int> par1, par2;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	if(i & 1){
    		par1.insert(A[i] % 2);
    	}else{
    		par2.insert(A[i] % 2);
    	}
    }

    if(par1.size() == 1 and par2.size() == 1){
    	cout << "YES" << '\n';
    }else{
    	cout << "NO" << "\n";
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