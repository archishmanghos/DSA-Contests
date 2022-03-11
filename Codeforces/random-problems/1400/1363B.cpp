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

    // all same
    char c = S[0];
    bool allSame = true;
    for(char i : S){
    	allSame &= i == c;
    }

    if(allSame){
    	cout << 0 << '\n';
    	return;
    }

    int ans = N, cnt[2] = {0};
    for(char c : S){
    	cnt[(c - '0')] += 1;
    }

    ans = min(ans, min(cnt[0], cnt[1]));

    // left 0, right 1
    for(int i = 0; i < N - 1; i++){
    	int count = 0;
    	for(int j = 0; j <= i; j++) {
    		count += S[j] == '1';
    	}
    	for(int j = i + 1; j < N; j++){
    		count += S[j] == '0';
    	}
    	ans = min(ans, count);
    }

    // left 1, right 0
    for(int i = 0; i < N - 1; i++){
    	int count = 0;
    	for(int j = 0; j <= i; j++) {
    		count += S[j] == '0';
    	}
    	for(int j = i + 1; j < N; j++){
    		count += S[j] == '1';
    	}
    	ans = min(ans, count);
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