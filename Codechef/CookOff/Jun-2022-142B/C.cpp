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

	if(N == 2) cout << 0 << '\n';
	else if(N % 2 == 0){
		N /= 2;
		if(N % 2 == 0){
			int a = N - 1, b = N + 1;
			int gcdd = __gcd(a, b);
			int lcmm = (a * b) / gcdd;
			cout << lcmm - gcdd << '\n';
		}else{
			int a = N - 2, b = N + 2;
			int gcdd = __gcd(a, b);
			int lcmm = (a * b) / gcdd;
			cout << lcmm - gcdd << '\n';
		}
	}else{
		N /= 2;
		int a = N, b = N + 1;
		int gcdd = __gcd(a, b);
		int lcmm = (a * b) / gcdd;
		cout << lcmm - gcdd << '\n';
	}
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