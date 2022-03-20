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

int T;
string S;

void solve()
{
    cin >> S;
    int N = S.size();
    vector<int> cnt(26, 0);

    for(char c : S){
    	cnt[c - 'a'] += 1;
    }

    int pos = 0;
    for(int i = 0; i < N; i++){
    	if(cnt[S[i] - 'a'] > 1){
    		pos += 1;
    		cnt[S[i] - 'a'] -= 1;
    	}else{
    		break;
    	}
    }

    cout << S.substr(pos) << '\n';
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