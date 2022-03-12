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

int A, B;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> A >> B;
	int pre = (A == 1 ? 10 : A - 1);
	int next = (A == 10 ? 1 : A + 1);

	if(pre == B or next == B){
		cout << "Yes";
	}else{
		cout << "No";
	}

    return 0;
}