#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;

int N, A[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    vector<int> squares(5, 0);
	int ans = 0;
	for(int i = 1; i <= N; i++){
		squares[1] += 1;
		for(int j = 4; j >= 1; j--){
			if(squares[j] > 0){
				squares[j] -= 1;
				if(j + A[i] > 4) ans += 1;
				else squares[j + A[i]] += 1;
			}
		}
	}

	cout << ans;

    return 0;
}