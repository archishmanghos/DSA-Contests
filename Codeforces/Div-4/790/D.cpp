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

int T, N, M, A[205][205];

bool isValid(int x, int y){
	return (x >= 1 and x <= N and y >= 1 and y <= M);
}

void solve() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= M; j++){
    		cin >> A[i][j];
    	}
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= M; j++){
    		int sum = A[i][j];
    		int curX = i, curY = j;
    		while(isValid(curX, curY)){
    			sum += A[curX][curY];
    			curX += 1;
    			curY += 1;
    		}

    		curX = i, curY = j;
    		while(isValid(curX, curY)){
    			sum += A[curX][curY];
    			curX -= 1;
    			curY += 1;
    		}

    		curX = i, curY = j;
    		while(isValid(curX, curY)){
    			sum += A[curX][curY];
    			curX += 1;
    			curY -= 1;
    		}

    		curX = i, curY = j;
    		while(isValid(curX, curY)){
    			sum += A[curX][curY];
    			curX -= 1;
    			curY -= 1;
    		}

    		sum -= 4 * A[i][j];
    		ans = max(ans, sum);
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