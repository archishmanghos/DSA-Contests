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

int T, N, A[mxN];

int minStepsToOdd(int x){
	int cntSteps = 0;
	while(x % 2 == 0) x /= 2, cntSteps += 1;
	return cntSteps;
}

void solve() {
	cin >> N;
	int odd = 0;
	for(int i = 1; i <= N; i++) cin >> A[i], odd += A[i] % 2 == 1;
	if(!odd){
		int minSteps = INF;
		for(int i = 1; i <= N; i++) minSteps = min(minSteps, minStepsToOdd(A[i]));
		cout << (minSteps + N - 1) << '\n';
	}else{
		cout << (N - odd) << '\n';
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