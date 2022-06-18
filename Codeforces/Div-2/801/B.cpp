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

int T, N, A;

void solve() {
	cin >> N;
	int joe = INF, mike = INF, indexJoe = -1, indexMike = -1;

	for(int i = 1; i <= N; i++){
		cin >> A;
		if(i & 1) {
			if(A < mike){
				mike = A;
				indexMike = i;
			}
		}
		else {
			if(A < joe){
				joe = A;
				indexJoe = i;
			}
		}
	}

	if(N & 1) cout << "Mike" << '\n';
	else {
		if(joe < mike) cout << "Mike" << '\n';
		else if(joe > mike) cout << "Joe" << '\n';
		else cout << (indexJoe < indexMike ? "Mike" : "Joe") << '\n';
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