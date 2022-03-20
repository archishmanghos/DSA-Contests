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

int T;
string S1, S2;

void solve()
{
    cin >> S1 >> S2;
    int i = 0, j = 0;
    int N1 = S1.size(), N2 = S2.size();

    while(i < N1 and j < N2){
    	if(S1[i] == S2[j]){
    		i += 1;
    		j += 1;
    	}else{
    		j += 1;
    	}
    }

    if(i == N1){
    	int ans = N2 - N1;
    	cout << ans << '\n';
    }else{
    	cout << "IMPOSSIBLE" << '\n';
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
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}