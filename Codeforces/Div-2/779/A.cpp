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
string S;

void solve()
{
	cin >> N >> S;
	int ans = 0, start = -1, end = 0;
	for(int i = 0; i < N; i++){
		if(start == -1 and S[i] == '0'){
			start = i;
		}
		if(S[i] == '0'){
			end = i;
		}
	}

	if(start == -1){
		cout << 0 << '\n';
		return;
	}

	int one = 0;
	for(int i = start + 1; i <= end; i++){
		if(S[i] == '0'){
			if(one < 2){
				ans += 2 - one;
			}
			one = 0;
		}else{
			one += 1;
		}
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