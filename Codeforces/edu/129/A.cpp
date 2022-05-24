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

int T, N, M, A[mxN], B[mxN];

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
	for(int i = 1; i <= M; i++) cin >> B[i];

	sort(A + 1, A + N + 1), sort(B + 1, B + M + 1);
	int curElement = -1, cur = 1;
	int ans1 = -1, ans2 = -1;
	while(true){
		bool done = false;
		if(cur){
			for(int i = N; i >= 1; i--){
				if(A[i] > curElement){
					curElement = A[i];
					done = true;
					break;
				}
			}
			if(!done){
				ans1 = 0;
				break;
			}
		}else{
			for(int i = M; i >= 1; i--){
				if(B[i] > curElement){
					curElement = B[i];
					done = true;
					break;
				}
			}
			if(!done){
				ans1 = 1;
				break;
			}
		}
		cur ^= 1;
	}

	cur = 0, curElement = -1;
	while(true){
		bool done = false;
		if(cur){
			for(int i = N; i >= 1; i--){
				if(A[i] > curElement){
					curElement = A[i];
					done = true;
					break;
				}
			}
			if(!done){
				ans2 = 0;
				break;
			}
		}else{
			for(int i = M; i >= 1; i--){
				if(B[i] > curElement){
					curElement = B[i];
					done = true;
					break;
				}
			}
			if(!done){
				ans2 = 1;
				break;
			}
		}
		cur ^= 1;
	}	

	cout << (!ans1 ? "Bob" : "Alice") << '\n' << (!ans2 ? "Bob" : "Alice") << '\n';
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