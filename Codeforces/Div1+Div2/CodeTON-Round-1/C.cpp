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
    vector<int> cnt(2, 0);
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	if(A[i] <= 1){
    		cnt[A[i]] += 1;
    	}
    }
    sort(A + 1, A + N + 1);

    if(cnt[0] and cnt[1]){
    	cout << "NO" << '\n';
    }else if(cnt[0]){
    	cout << "YES" << '\n';
    }else if(cnt[1]){
    	bool ok = true;
    	int pre = 1;
    	for(int i = 1 + cnt[1]; i <= N; i++){
			if(A[i] - pre == 1){
				ok = false;
				break;
			}
    		pre = A[i];
    	}
    	cout << (ok ? "YES" : "NO") << '\n';
    }else{
    	cout << "YES" << '\n';
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