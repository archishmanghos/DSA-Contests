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
vector<int> A(mxN);

void solve()
{
    cin >> N;
    set<int> s;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	s.insert(A[i]);
    }

    vector<int> v;
    for(int i : s){
    	v.push_back(i);
    }

    N = v.size();
    int mex = -1, j = 0;
    for(int i = 0; i < N; i++){
    	if(v[i] != j){
    		mex = j;
    		break;
    	}
    	j += 1;
    }
    if(mex == -1){
    	mex = j;
    	cout << (mex == 1 ? -1 : 0) << '\n';
    	return;
    }

    debug(mex)

    debug(v)
    if(mex == 0){
    	cout << v[0] - 1 << '\n';
    }else if(mex == 1){
    	cout << -1 << '\n';
    }else{
    	int ans = 0, cnt = 1;
    	for(int i = mex; i < N - 1; i++){
    		if(v[i] + 1 == v[i + 1]){
    			cnt += 1;
    		}else{
    			ans += (cnt + 1 >= mex);
    			cnt = 1;
    		}
    	}
    	ans += (cnt + 1 >= mex);
    	cout << ans << '\n';
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