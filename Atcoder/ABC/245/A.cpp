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

int A, B, C, D;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> A >> B >> C >> D;
	if(A < C){
		cout << "Takahashi";
	}else if(A > C){
		cout << "Aoki";
	}else{
		if(B <= D){
			cout << "Takahashi";
		}else{
			cout << "Aoki";
		}
	}

    return 0;
}