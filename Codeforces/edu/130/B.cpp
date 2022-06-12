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

int N, Q, X, Y;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	sort(A.begin(), A.end());
	for(int i = 1; i < N; i++) A[i] += A[i - 1];

	while(Q--){
		cin >> X >> Y;
		int index = N - X;
		int indexUpto = N - X + Y - 1;
		int ans = 0;
		if(index > 0) ans -= A[index - 1];
		ans += A[indexUpto];
		cout << ans << '\n';
	}

    return 0;
}