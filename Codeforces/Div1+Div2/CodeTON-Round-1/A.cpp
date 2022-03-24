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

int T, N;
vector<pair<int, int>> A(mxN);

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++){
    	cin >> A[i].first;
    	A[i].second = i;
    }

    if(N <= 2){
    	if(N == 1){
    		cout << 1 << ' ' << 1 << '\n';
    	}else{
    		cout << 1 << ' ' << 2 << '\n';
    	}
    	return;
    }

    sort(A.begin() + 1, A.begin() + N + 1);
    int i = A[1].second;
    int j = A[N].second;
    if(i > j){
    	swap(i, j);
    }

    cout << i << ' ' << j << '\n';
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