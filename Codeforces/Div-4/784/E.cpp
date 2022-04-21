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
string S[mxN];

void solve()
{
 	cin >> N;
 	vector<int> firstL(26, 0), secondL(26, 0);
 	unordered_map<string, int> mp;

 	for(int i = 1; i <= N; i++){
 		cin >> S[i];
 	}


 	int ans = 0;
 	for(int i = N; i >= 1; i--){
 		ans += firstL[S[i][0] - 'a'] + secondL[S[i][1] - 'a'];
 		if(mp.find(S[i]) != mp.end()){
 			ans -= 2 * mp[S[i]];
 		}
 		firstL[S[i][0] - 'a'] += 1;
 		secondL[S[i][1] - 'a'] += 1;
 		mp[S[i]] += 1;
 	}

 	cout << ans << '\n';
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