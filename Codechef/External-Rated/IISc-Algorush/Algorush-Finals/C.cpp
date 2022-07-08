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

int T;

void solve() {
    
    int n, m;
    cin >> n >> m;

    vector<int>h(n + 3, 0);

    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }

    int sq = 33;
    vector<vector<int>>sparse(n + 3, vector<int>(sq + 1, 0));

    for(int i = 1; i <= n; i++)sparse[i][0] = h[i];
    for(int i = 1; i <= sq; i++){
        for(int j = 1; j <= n; j++){
            sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];
    	}
    }

    for(int i = 0; i < m; i++){
        int s, k;
        cin >> s >> k;

        for(int j = 0; j < 31; j++){
            int bit = (k >> j) & 1;
            if(bit)s = sparse[s][j];
		}

        cout << s << '\n';
	}
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    // cin >> T;
    T=1;
    while (T--)
        solve();

    return 0;
}