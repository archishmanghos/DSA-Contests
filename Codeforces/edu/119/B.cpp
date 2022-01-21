#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int W, H;
    cin >> W >> H;
    int ans = -INF;

    for(int i = 1; i <= 2; i++){
        int K, minn, maxx;
        cin >> K;
        cin >> minn;
        for(int j = 2; j <= K; j++){
            cin >> maxx;
        }
        ans = max(ans, (maxx - minn) * H);
    }

    for(int i = 1; i <= 2; i++){
        int K, minn, maxx;
        cin >> K;
        cin >> minn;
        for(int j = 2; j <= K; j++){
            cin >> maxx;
        }
        ans = max(ans, (maxx - minn) * W);
    }

    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}