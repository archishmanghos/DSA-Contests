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
    multiset<int> mexToBe;
    set<int> s, mex;
    int pre = -1;
    bool ok = true;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	if(A[i] != -1){
    		if(A[i] > i or A[i] < pre){
    			ok = false;
    		}
    		mexToBe.insert(A[i]);
    		mex.insert(A[i]);
    		pre = A[i];
    	}
    }

    if(!ok){
    	cout << -1 << '\n';
    	return;
    }

    for(int i = 0; i <= 2 * N; i++){
    	if(mex.find(i) == mex.end()){
    		s.insert(i);
    	}
    }

    vector<int> ans;
    int k = 1, l = 1;
    auto it = mexToBe.begin();

    for(int i = 1; i <= N; i++){
    	if(A[i] != -1){
    		if(k < l){
    			int x = *mex.begin();
    			ans.push_back(x);
    			mex.erase(x);
    			k += 1;
    			int pre = *it;
    			it++;
    			if(it != mexToBe.end() and * it != pre){
    				l += 1;
    			}
    		}else{
    			int pre = *it;
    			int x = *s.begin();
    			ans.push_back(x);
    			s.erase(x);
    			it++;
    			if(it != mexToBe.end() and * it != pre){
    				l += 1;
    			}
    		}
    	}else{
    		int x = *s.begin();
			ans.push_back(x);
			s.erase(x);
    	}
    }

    set<int> checkMex;
    for(int i = 0; i < N; i++){
    	checkMex.insert(i);
    }

    for(int i = 0; i < ans.size(); i++){
    	checkMex.erase(ans[i]);
    	int mex = (checkMex.size() ? *checkMex.begin() : N);
    	if(A[i + 1] != -1 and mex != A[i + 1]){
    		cout << -1 << '\n';
    		return;
    	}
    }

   	for(int i : ans){
   		cout << i << ' ';
   	}
   	cout << '\n';
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