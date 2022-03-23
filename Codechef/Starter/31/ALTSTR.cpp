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
	int cnt[2] = {0};

	for(char c : S){
		cnt[c - '0'] += 1;
	}

	if(cnt[0] == cnt[1]){
		cout << N << '\n';
	}else{
		cout << min(cnt[0], cnt[1]) * 2 + 1 << '\n';
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