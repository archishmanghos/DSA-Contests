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

int V, A, B, C;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> V >> A >> B >> C;
	while(V >= 0){
		if(A > V){
			cout << 'F';
			return 0;
		}
		V -= A;
		debug(V)
		if(B > V){
			cout << 'M';
			return 0;
		}
		V -= B;
		debug(V)
		if(C > V){
			cout << 'T';
			return 0;
		}
		V -= C;
		debug(V)
	}

    return 0;
}