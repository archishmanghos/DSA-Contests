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

int T, N;
string S;

void solve()
{
	cin >> N >> S;
	int cntOpen = 0, cntClose = 0, operations = 0, remains = N;
	char start;
	bool regular = false;

	for(int i = 0; i < N; i++){
		if(S[i] == '('){
			if(!cntOpen and !cntClose){
				start = S[i];
			}
			cntOpen += 1;
		}else{
			if(cntOpen){
				cntOpen -= 1;
				if(!cntOpen){
					regular = true;
				}
			}
			if(!cntOpen and !cntClose){
				start = S[i];
			}
			cntClose += 1;
		}

		if(regular){
			operations += 1;
			remains = N - i - 1;
			regular = false;
			cntOpen = cntClose = 0;
		}else if(S[i] == start){
			if((start == '(' and cntOpen == 2 and cntClose >= 0) or (start == ')' and cntClose == 2 and cntOpen >= 0)){
				operations += 1;
				remains = N - i - 1;
				cntOpen = cntClose = 0;
				regular = false;
			}
		}
	}

	cout << operations << ' ' << remains << '\n';
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