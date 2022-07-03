#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;

void solve() {
    
    cin >> N;
    if(N == 3){
    	cout << -1 << '\n';
    	return;
    }
    int A[N + 2];
    for(int i = 1; i <= N; i++) A[i] = i;
    if(N % 2 == 0) swap(A[2], A[N]);
	else swap(A[1], A[N]);

    for(int i = 1; i <= N; i++) cout << A[i] << ' ';
    cout << '\n';
}

int32_t main() {
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