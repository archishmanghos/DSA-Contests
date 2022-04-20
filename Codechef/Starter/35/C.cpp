#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e9 + 7;

int T, N;
vector<int> A(mxN);

void solve()
{
    cin >> N;
    vector<int> odd, even;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	if(A[i] % 2 == 0){
    		even.push_back(i);
    	}else{
    		odd.push_back(i);
    	}
    }

    int par1 = A[1] % 2, par2 = A[N] % 2;
    if(par1 == par2){
    	if(par1 == 0){
    		cout << even.size() - 1 << '\n';
    	}else{
    		cout << odd.size() - 1 << '\n';
    	}
    }else{
    	if(par1 == 0){
    		int ans = INF;
    		for(int i = 0; i < even.size(); i++){
    			int index = lower_bound(odd.begin(), odd.end(), even[i]) - odd.begin();
    			ans = min(ans, i + ((int)odd.size() - index));
    		}
    		cout << ans << '\n';
    	}else{
    		int ans = INF;
    		for(int i = 0; i < odd.size(); i++){
    			int index = lower_bound(even.begin(), even.end(), odd[i]) - even.begin();
    			ans = min(ans, i + ((int)even.size() - index));
    		}
    		cout << ans << '\n';
    	}
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