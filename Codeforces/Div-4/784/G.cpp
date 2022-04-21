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

int T, N, M;
char A[55][55];

void solve()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= M; j++){
    		cin >> A[i][j];
    	}
    }

    for(int j = 1; j <= M; j++){
    	int cntStone = 0;
    	for(int i = 1; i <= N; i++){
    		if(A[i][j] == 'o'){
    			for(int k = i - 1; k >= 1; k--){
    				if(A[k][j] == 'o'){
						break;
					}else if(cntStone){
						A[k][j] = '*';
						cntStone -= 1;
					}else{
						A[k][j] = '.';
					}
    			}
    			cntStone = 0;
    		}else if(A[i][j] == '*'){
    			cntStone += 1;
    		}
    	}
    	if(cntStone){
    		for(int k = N; k >= 1; k--){
				if(A[k][j] == 'o'){
					break;
				}else if(cntStone){
					A[k][j] = '*';
					cntStone -= 1;
				}else{
					A[k][j] = '.';
				}
			}
    	}
    }

    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= M; j++){
    		cout << A[i][j];
    	}
    	cout << '\n';
    }
}

int32_t main()
{
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