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

int T, rating;

void solve()
{
    cin >> rating;
    if(rating <= 1399){
    	cout << "Division 4" << '\n';
    }else if(rating <= 1599){
    	cout << "Division 3" << '\n';
    }else if(rating <= 1899){
    	cout << "Division 2" << '\n';
    }else{
    	cout << "Division 1" << '\n';
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