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

int T, N, M, K;
string A, B;

void solve() {
	cin >> N >> M >> K >> A >> B;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	string ans = "";
	int i = 0, j = 0, cnt = 0, pointer = -1;
	while(i < N and j < M){
		if(cnt < K){
			if(A[i] < B[j]) {
				if(pointer == 1) cnt += 1;
				else cnt = 1;
				ans += A[i++];
				pointer = 1;
			}
			else {
				if(!pointer) cnt += 1;
				else cnt = 1;
				ans += B[j++];
				pointer = 0;
			}
		}else{
			if(pointer) ans += B[j++], pointer = 0;
			else ans += A[i++], pointer = 1;
			cnt = 1;
		}
	}

	cout << ans << '\n';
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