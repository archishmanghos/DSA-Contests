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

void findLIS(vector<int> &v){
	vector<int> lis;
    for(int i = 1; i <= N; i++){
    	if(lis.size() == 0){
    		lis.push_back(A[i]);
    	}else{
    		if(A[i] > lis.back()){
    			lis.push_back(A[i]);
    		}else{
    			int index = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
    			lis[index] = A[i];
    		}
    	}
    	v[i] = lis.size();
    }
}

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    vector<int> prefixLIS(N + 2), suffixLIS(N + 2);
    findLIS(prefixLIS);
    reverse(A + 1, A + N + 1);
    for(int i = 1; i <= N; i++){
    	A[i] *= -1;
    }
    findLIS(suffixLIS);
    reverse(suffixLIS.begin() + 1, suffixLIS.begin() + N + 1);

    int ans = 0;
    for(int i = 1; i <= N; i++){
    	if(i == N){
    		ans = max(ans, prefixLIS[i]);
    	}else{
    		ans = max(ans, prefixLIS[i] + suffixLIS[i + 1]);
    	}
    }

    cout << min(ans, N) << '\n';
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