#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int N, X, A, B;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N >> X;
    int minGameTime = INF, time = 0, ans = INF;
    for(int i = 1; i <= N; i++){
    	cin >> A >> B;
    	minGameTime = min(minGameTime, B);
    	time += (A + B);
    	ans = min(ans, time + minGameTime * (X - 1));
    	X -= 1;
    }

    cout << ans;

    return 0;
}