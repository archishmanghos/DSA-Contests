#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e9;

int T;
vector<int> full;

void solve()
{
    int N;
    cin >> N;

    if(N > full.size()){
    	cout << "NO" << '\n';
    }else{
    	cout << "YES" << '\n';
    	for(int i = 0; i < N; i++){
    		cout << full[i] << ' ';
    	}
    	cout << '\n';
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	full.push_back(1);

	while(full.back()*3<=INF){
		full.push_back(full.back()*3);
	}

    cin >> T;
    while (T--)
        solve();

    return 0;
}