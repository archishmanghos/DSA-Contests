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
    int odd = 0, even = 0;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	odd += A[i] % 2 == 1;
    	even += A[i] % 2 == 0;
    }	

    if(odd % 2 == 0){
    	cout << min(even, (odd + 1) / 2) << '\n';
    }else{
    	cout << even << '\n';
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