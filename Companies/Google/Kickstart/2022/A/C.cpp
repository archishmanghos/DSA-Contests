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

bool check(string X, int N){
	int pal = 0;
	for(int l = 5; l <= 15; l++){
		for(int m = 0; m <= (N - l); m++){
			for(int i = m; i < m + l; i++){
				int j = i, k = i + l - 1;
				bool ok = true;
				while(j < k){
					if(X[j] != X[k]){
						ok = false;
						break;
					}
					j += 1;
					k -= 1;
				}
				pal += ok;
			}
		}
	}

	return pal == 0;
}

void solve()
{
	cin >> N >> S;
	int qm = 0;
	vector<int> index;
	for(int i = 0; i < N; i++){
		if(S[i] == '?'){
			qm += 1;
			index.push_back(i);
		}
	}

	for(int i = 0; i < (1 << qm); i++){
		string t = S;
		for(int j = 0; j < qm; j++){
			if((i & (1 << j)) != 0){
				t[index[j]] = '1';
			}else{
				t[index[j]] = '0';
			}
		}

		if(check(t, N)){
			cout << "POSSIBLE" << '\n';
			return;
		}
	}

	cout << "IMPOSSIBLE" << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}