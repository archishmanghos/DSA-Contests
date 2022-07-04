#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int T, N, M;

void solve() {
    
    cin >> N >> M;
    string S1 = "", S2 = "";
    for(int i = 1; i <= N / 4; i++) S1 += "1001", S2 += "0110";
    if(N % 4 == 1) S1 += "1", S2 += "0";
	if(N % 4 == 2) S1 += "10", S2 += "01";
	if(N % 4 == 3) S1 += "100", S2 += "011";

	int cur = 0;
	vector<vector<int>> ans(N + 2, vector<int>(M + 2));
	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= N; j++){
			if(cur == 1 or cur == 2) ans[j][i] = S2[j - 1] - '0';
			else ans[j][i] = S1[j - 1] - '0';
		}
		cur = (cur + 1) % 4;
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
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