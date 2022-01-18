#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;
vector<vector<int>> setBit(mxN, vector<int>(20, 0));

void solve()
{
    int L, R;
    cin >> L >> R;

    int ans = R - L + 1;
    for(int i = 0; i < 20; i++){
        ans = min(ans, R - L + 1 - (setBit[R][i] - setBit[L - 1][i]));
    }

    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 200000; i++){
        for(int j = 0; j < 20; j++){
            setBit[i][j] += ((i & (1 << j)) != 0);
            if(i > 1){
                setBit[i][j] += setBit[i - 1][j];
            }
        }
    }

    cin >> T;
    while (T--)
        solve();

    return 0;
}