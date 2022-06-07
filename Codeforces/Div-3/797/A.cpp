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
	int a = 2, b = 3, c = 1;
	N -= 6;
	if(N % 3 == 0){
		a += N / 3, b += N / 3, c += N / 3;
	}else if(N % 3 == 1){
		a += N / 3, b += N / 3 + 1, c += N / 3;
	}else{
		a += N / 3 + 1, b += N / 3 + 1, c += N / 3;
	}

	cout << a << ' ' << b << ' ' << c << '\n';
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